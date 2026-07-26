// Pattern: Token bucket rate limiter and consistent hashing
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check rate_limiter_and_consistent_hashing.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// Two primitives that show up in any distributed service.

// A token bucket rate limiter. Tokens accumulate at a fixed rate up to a cap; each request
// spends one.
//
// The cap is what distinguishes it from a fixed window: it permits a burst up to the bucket
// size while still bounding the long-run average. A fixed counter per window allows twice
// the intended rate across a window boundary - the classic failure - and a token bucket
// cannot, because the tokens simply are not there.
//
// Refilling lazily on each request rather than on a timer means no background work and no
// clock drift: the bucket is a function of the elapsed time since the last check.
class TokenBucket {
  double capacity;
  double tokens;
  double refill_per_second;
  double last_check;

 public:
  TokenBucket(double capacity, double refill_per_second, double now)
      : capacity(capacity), tokens(capacity), refill_per_second(refill_per_second),
        last_check(now) {}

  bool allow(double now, double cost = 1.0) {
    const double elapsed = max(0.0, now - last_check);
    tokens = min(capacity, tokens + elapsed * refill_per_second);
    last_check = now;
    if (tokens < cost) return false;
    tokens -= cost;
    return true;
  }

  double available() const { return tokens; }
};

// Consistent hashing. Nodes and keys are both hashed onto a ring, and a key belongs to the
// first node clockwise from it.
//
// Plain modulo hashing - node = hash(key) % n - remaps nearly every key when n changes, so
// adding one server invalidates the whole cache. On a ring, adding a node only steals keys
// from its immediate successor: about 1/n of them move, and nothing else is disturbed. That
// is the entire reason the structure exists.
//
// Virtual nodes are not optional in practice. With one point per node the ring is uneven -
// some node owns a much larger arc by chance - and removing a node dumps all its keys on a
// single neighbour. Several points per node smooth both problems.
class HashRing {
  map<uint64_t, string> ring;  // ordered, so the successor lookup is a tree search
  size_t replicas;
  set<string> nodes;

  static uint64_t hash_of(const string& key) {
    uint64_t h = 14695981039346656037ULL;  // FNV-1a
    for (char c : key) {
      h ^= static_cast<unsigned char>(c);
      h *= 1099511628211ULL;
    }
    return h;
  }

 public:
  explicit HashRing(size_t replicas = 100) : replicas(replicas) {}

  void add(const string& node) {
    nodes.insert(node);
    for (size_t i = 0; i < replicas; ++i) ring[hash_of(node + "#" + to_string(i))] = node;
  }

  void remove(const string& node) {
    nodes.erase(node);
    for (size_t i = 0; i < replicas; ++i) ring.erase(hash_of(node + "#" + to_string(i)));
  }

  // The first node clockwise, wrapping past the end of the ring.
  string owner(const string& key) const {
    if (ring.empty()) return "";
    auto it = ring.lower_bound(hash_of(key));
    if (it == ring.end()) it = ring.begin();  // the wrap is what makes it a ring
    return it->second;
  }

  size_t node_count() const { return nodes.size(); }
};

int main() {
  // Capacity 5, refilling 1 per second. Five requests burst through, the sixth does not.
  TokenBucket bucket(5, 1, 0.0);
  for (int i = 0; i < 5; ++i) assert(bucket.allow(0.0));
  assert(!bucket.allow(0.0));

  // One second later, exactly one token is back.
  assert(bucket.allow(1.0));
  assert(!bucket.allow(1.0));

  // Idle time accumulates only up to the cap, which is what bounds the burst.
  assert(bucket.allow(1000.0));
  assert(bucket.available() < 5.0);
  TokenBucket idle(5, 1, 0.0);
  for (int i = 0; i < 5; ++i) idle.allow(0.0);
  assert(idle.allow(1000.0));  // refilled
  int granted = 1;
  while (idle.allow(1000.0)) ++granted;
  assert(granted == 5);  // never more than the capacity

  HashRing ring;
  for (const string& node : {"cache-a", "cache-b", "cache-c"}) ring.add(node);
  assert(ring.node_count() == 3);

  // Deterministic: the same key always lands on the same node.
  const vector<string> keys = {"user:1", "user:2", "user:3", "session:abc", "page:home"};
  vector<string> before;
  for (const string& key : keys) before.push_back(ring.owner(key));
  for (size_t i = 0; i < keys.size(); ++i) assert(ring.owner(keys[i]) == before[i]);

  // Adding a node must move only a minority of keys. With modulo hashing nearly all of them
  // would move, which is the whole comparison.
  ring.add("cache-d");
  size_t moved = 0;
  for (size_t i = 0; i < keys.size(); ++i)
    if (ring.owner(keys[i]) != before[i]) ++moved;
  assert(moved <= keys.size() / 2);

  // Measured over many keys, the fraction moved should be close to 1/n.
  HashRing wide;
  for (const string& node : {"n1", "n2", "n3", "n4"}) wide.add(node);
  vector<string> owners;
  const size_t sample = 2000;
  for (size_t i = 0; i < sample; ++i) owners.push_back(wide.owner("k" + to_string(i)));
  wide.add("n5");
  size_t relocated = 0;
  for (size_t i = 0; i < sample; ++i)
    if (wide.owner("k" + to_string(i)) != owners[i]) ++relocated;
  // Expected around 1/5; allow a generous band for hash variance.
  assert(relocated > sample / 20 && relocated < sample / 2);

  // Removing a node reassigns its keys and leaves the rest alone.
  wide.remove("n5");
  assert(wide.node_count() == 4);
  size_t restored = 0;
  for (size_t i = 0; i < sample; ++i)
    if (wide.owner("k" + to_string(i)) == owners[i]) ++restored;
  assert(restored == sample);  // back to exactly the original assignment

  HashRing empty;
  assert(empty.owner("anything").empty());
  return 0;
}
