// Pattern: Bloom filter
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check bloom_filter.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <string>
#include <vector>

using namespace std;

// A Bloom filter answers set membership in constant time and constant space per element,
// with one deliberate compromise: it can say yes to something absent, but never no to
// something present.
//
// That asymmetry is what makes it useful. A database can consult a Bloom filter before
// touching disk - a "no" is certain, so the disk read is skipped entirely, and a "yes" costs
// only the read that would have happened anyway. False positives cost work, never
// correctness.
//
// k hash functions set k bits per insertion. Too few and different elements collide on the
// same bit; too many and the array fills up. The optimum is k = (m/n) ln 2 for m bits and n
// elements, giving a false positive rate of about 0.6185^(m/n) - roughly 1% at 10 bits per
// element.
//
// Deletion is impossible: clearing a bit could unset one shared with another element. A
// counting Bloom filter replaces each bit with a small counter to allow it, at several times
// the space.
class BloomFilter {
  vector<bool> bits;
  size_t hash_count;

  // Two independent hashes generate k by linear combination, which is standard practice:
  // it is indistinguishable in effect from k separate hashes and costs two.
  size_t nth_hash(const string& key, size_t n) const {
    uint64_t a = 14695981039346656037ULL;  // FNV-1a
    for (char c : key) {
      a ^= static_cast<unsigned char>(c);
      a *= 1099511628211ULL;
    }
    uint64_t b = a;
    b ^= b >> 33;
    b *= 0xff51afd7ed558ccdULL;
    b ^= b >> 33;
    return static_cast<size_t>((a + n * b) % bits.size());
  }

 public:
  BloomFilter(size_t bit_count, size_t hash_count)
      : bits(bit_count, false), hash_count(hash_count) {}

  void insert(const string& key) {
    for (size_t n = 0; n < hash_count; ++n) bits[nth_hash(key, n)] = true;
  }

  // False on the right of the return is certain; true is only probable.
  bool might_contain(const string& key) const {
    for (size_t n = 0; n < hash_count; ++n)
      if (!bits[nth_hash(key, n)]) return false;
    return true;
  }

  double load() const {
    size_t set = 0;
    for (bool bit : bits) if (bit) ++set;
    return static_cast<double>(set) / static_cast<double>(bits.size());
  }
};

int main() {
  BloomFilter filter(10000, 5);
  const vector<string> present = {"alice", "bob", "carol", "dave"};
  for (const string& key : present) filter.insert(key);

  // No false negatives, ever. This is the property the structure guarantees.
  for (const string& key : present) assert(filter.might_contain(key));

  // False positives are possible but rare at this load. Measure rather than assume.
  size_t false_positives = 0;
  const size_t probes = 10000;
  for (size_t i = 0; i < probes; ++i)
    if (filter.might_contain("absent-" + to_string(i))) ++false_positives;
  assert(false_positives < probes / 100);  // well under 1% with 4 elements in 10000 bits
  assert(filter.load() < 0.01);

  // A deliberately overloaded filter: 64 bits, 200 elements. Every probe now returns true,
  // which is the failure mode to know about - the filter degrades to useless, not to wrong.
  BloomFilter saturated(64, 5);
  for (int i = 0; i < 200; ++i) saturated.insert("key-" + to_string(i));
  assert(saturated.load() > 0.9);
  assert(saturated.might_contain("never-inserted"));

  // An empty filter says no to everything, with certainty.
  BloomFilter empty(1000, 3);
  assert(!empty.might_contain("anything"));
  return 0;
}
