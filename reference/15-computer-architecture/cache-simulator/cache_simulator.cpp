// Pattern: Cache simulator
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check cache_simulator.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <list>
#include <vector>

using namespace std;

// A set-associative cache simulator.
//
// An address splits into three fields, and the split is the whole design:
//
//   | tag | set index | block offset |
//
//   block offset  picks the byte inside a block  (log2 of the block size)
//   set index     picks which set the block maps to  (log2 of the set count)
//   tag           what is left, stored to identify the block
//
// Associativity is the number of blocks per set. One block per set is direct mapped:
// fastest lookup, and two hot addresses mapping to the same set evict each other
// forever - conflict misses. One set holding everything is fully associative: no
// conflict misses, and every lookup compares every tag. Real caches sit between,
// typically 4 to 16 ways, because the conflict curve flattens quickly and the
// comparator cost does not.
//
// The three kinds of miss need different fixes, which is why separating them matters:
//   compulsory  first reference to a block; only prefetching helps
//   capacity    the working set exceeds the cache; only a bigger cache helps
//   conflict    enough room, wrong mapping; more associativity helps
class Cache {
 public:
  enum class Policy { LRU, FIFO };

  struct Stats {
    long long hits = 0;
    long long misses = 0;
    long long evictions = 0;
    double hit_rate() const {
      const long long total = hits + misses;
      return total == 0 ? 0.0 : static_cast<double>(hits) / static_cast<double>(total);
    }
  };

 private:
  int block_bits = 0;
  int index_bits = 0;
  size_t ways;
  Policy policy;
  // One list of tags per set, ordered most recently used first under LRU and most
  // recently inserted first under FIFO.
  vector<list<uint64_t>> sets;
  Stats stats;

 public:
  Cache(size_t block_size, size_t set_count, size_t ways, Policy policy)
      : ways(ways), policy(policy), sets(set_count) {
    while ((size_t(1) << block_bits) < block_size) ++block_bits;
    while ((size_t(1) << index_bits) < set_count) ++index_bits;
  }

  bool access(uint64_t address) {
    const uint64_t block = address >> block_bits;
    const uint64_t index =
        (sets.size() == 1) ? 0 : (block & ((uint64_t(1) << index_bits) - 1));
    const uint64_t tag = block >> index_bits;

    list<uint64_t>& set = sets[index];
    auto found = find(set.begin(), set.end(), tag);

    if (found != set.end()) {
      ++stats.hits;
      // Only LRU reorders on a hit. FIFO evicts by insertion order, so a hit must
      // leave the order alone - that is the entire difference between them.
      if (policy == Policy::LRU) set.splice(set.begin(), set, found);
      return true;
    }

    ++stats.misses;
    if (set.size() == ways) {
      set.pop_back();  // least recent under LRU, oldest under FIFO
      ++stats.evictions;
    }
    set.push_front(tag);
    return false;
  }

  const Stats& statistics() const { return stats; }
};

// Average memory access time. The figure that decides designs, because a cache with a
// slightly worse hit rate and a much lower penalty can still be faster.
//
//   AMAT = hit time + miss rate x miss penalty
double average_access_time(double hit_time, double miss_rate, double miss_penalty) {
  return hit_time + miss_rate * miss_penalty;
}

// Amdahl's law: the gain from improving one part is capped by the part left alone.
// With 90% of the time made infinitely fast, the ceiling is still 10x.
double amdahl_speedup(double improvable_fraction, double improvement_factor) {
  return 1.0 / ((1.0 - improvable_fraction) + improvable_fraction / improvement_factor);
}

int main() {
  // Direct mapped, 4 sets, 16-byte blocks. Addresses 0 and 64 both map to set 0 and
  // evict each other on every access: the textbook conflict miss.
  Cache direct(16, 4, 1, Cache::Policy::LRU);
  for (int repeat = 0; repeat < 4; ++repeat) { direct.access(0); direct.access(64); }
  assert(direct.statistics().hits == 0);
  assert(direct.statistics().misses == 8);

  // The same trace on a 2-way cache: the conflict disappears.
  Cache two_way(16, 4, 2, Cache::Policy::LRU);
  for (int repeat = 0; repeat < 4; ++repeat) { two_way.access(0); two_way.access(64); }
  assert(two_way.statistics().misses == 2);  // compulsory only
  assert(two_way.statistics().hits == 6);

  // Spatial locality: a 16-byte block holds four 4-byte words, so a sequential walk
  // misses once per block and hits three times.
  Cache sequential(16, 16, 1, Cache::Policy::LRU);
  for (uint64_t address = 0; address < 64; address += 4) sequential.access(address);
  assert(sequential.statistics().misses == 4);
  assert(sequential.statistics().hits == 12);

  // LRU against FIFO on a trace built to separate them. Two ways, one set: A B A C.
  // LRU evicts B for C and keeps A; FIFO evicts A regardless of the hit.
  Cache lru(16, 1, 2, Cache::Policy::LRU);
  for (uint64_t block : {0, 16, 0, 32}) lru.access(block);
  Cache fifo(16, 1, 2, Cache::Policy::FIFO);
  for (uint64_t block : {0, 16, 0, 32}) fifo.access(block);
  // Ask for A again: LRU still holds it, FIFO threw it out.
  assert(lru.access(0));
  assert(!fifo.access(0));

  // A 95% hit rate with a 100-cycle penalty still costs 6 cycles a reference.
  assert(average_access_time(1.0, 0.05, 100.0) == 6.0);
  assert(average_access_time(1.0, 0.0, 100.0) == 1.0);

  const double ceiling = amdahl_speedup(0.9, 1e9);
  assert(ceiling > 9.99 && ceiling < 10.0);
  assert(amdahl_speedup(0.5, 2.0) == 4.0 / 3.0);
  return 0;
}
