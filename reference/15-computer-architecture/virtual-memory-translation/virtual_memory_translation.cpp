// Pattern: Virtual memory translation
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check virtual_memory_translation.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <list>
#include <unordered_map>

using namespace std;

// Virtual to physical translation through a two-level page table, with a TLB.
//
// A single-level table for a 32-bit space with 4 KiB pages needs 2^20 entries per
// process, allocated whether or not the process uses that memory. Splitting the page
// number in two lets second-level tables exist only where pages are actually mapped:
// a process touching 1 MiB pays for one second-level table, not for a million entries.
//
//   | level-1 index (10) | level-2 index (10) | page offset (12) |
//
// The cost is that every access now needs two memory reads before the real one. The
// TLB makes that affordable - a small fully-associative cache of recent translations,
// with hit rates typically above 99% because page locality is even stronger than data
// locality.
class PageTable {
 public:
  static constexpr int kOffsetBits = 12;  // 4 KiB pages
  static constexpr int kIndexBits = 10;   // 1024 entries per level
  static constexpr uint32_t kNotMapped = 0xFFFFFFFF;

  struct Stats {
    long long tlb_hits = 0;
    long long tlb_misses = 0;
    long long page_faults = 0;
    long long table_walks = 0;
  };

 private:
  // Second-level tables are created on demand, which is the point of the hierarchy.
  unordered_map<uint32_t, unordered_map<uint32_t, uint32_t>> levels;
  size_t tlb_capacity;
  list<pair<uint32_t, uint32_t>> tlb;  // (virtual page, frame), newest first
  unordered_map<uint32_t, list<pair<uint32_t, uint32_t>>::iterator> tlb_index;
  Stats stats;

  static uint32_t level_one(uint32_t page) { return page >> kIndexBits; }
  static uint32_t level_two(uint32_t page) { return page & ((1u << kIndexBits) - 1); }

  void tlb_insert(uint32_t page, uint32_t frame) {
    if (tlb.size() == tlb_capacity) {
      tlb_index.erase(tlb.back().first);
      tlb.pop_back();
    }
    tlb.emplace_front(page, frame);
    tlb_index[page] = tlb.begin();
  }

 public:
  explicit PageTable(size_t tlb_entries) : tlb_capacity(tlb_entries) {}

  void map(uint32_t page, uint32_t frame) {
    levels[level_one(page)][level_two(page)] = frame;
  }

  uint32_t translate(uint32_t virtual_address) {
    const uint32_t page = virtual_address >> kOffsetBits;
    const uint32_t offset = virtual_address & ((1u << kOffsetBits) - 1);

    auto cached = tlb_index.find(page);
    if (cached != tlb_index.end()) {
      ++stats.tlb_hits;
      tlb.splice(tlb.begin(), tlb, cached->second);  // LRU promotion
      return (cached->second->second << kOffsetBits) | offset;
    }
    ++stats.tlb_misses;

    // The walk: two dependent lookups, either of which can be absent.
    ++stats.table_walks;
    auto first = levels.find(level_one(page));
    if (first == levels.end()) { ++stats.page_faults; return kNotMapped; }
    auto second = first->second.find(level_two(page));
    if (second == first->second.end()) { ++stats.page_faults; return kNotMapped; }

    tlb_insert(page, second->second);
    return (second->second << kOffsetBits) | offset;
  }

  // How many second-level tables actually exist. On a sparse address space this is far
  // below 1024, which is the saving the hierarchy buys.
  size_t allocated_tables() const { return levels.size(); }
  const Stats& statistics() const { return stats; }
};

int main() {
  PageTable memory(4);  // a deliberately tiny TLB, so eviction is observable
  memory.map(0x00000, 0x100);
  memory.map(0x00001, 0x200);
  memory.map(0x00400, 0x300);  // a different level-1 index

  // The offset passes through untouched; only the page number is translated.
  assert(memory.translate(0x00000ABC) == 0x00100ABC);
  assert(memory.translate(0x00001FFF) == 0x00200FFF);
  assert(memory.translate(0x00400000) == 0x00300000);

  // Unmapped pages fault rather than returning a wrong frame.
  assert(memory.translate(0x00002000) == PageTable::kNotMapped);
  assert(memory.statistics().page_faults == 1);

  // Three sparse pages need two second-level tables, not 1024.
  assert(memory.allocated_tables() == 2);

  // Repeated access to the same page hits the TLB and skips the walk.
  const long long walks_before = memory.statistics().table_walks;
  for (int i = 0; i < 10; ++i) memory.translate(0x00000100);
  assert(memory.statistics().table_walks == walks_before);

  // Locality is what the TLB depends on. A walk across more pages than it holds
  // evicts everything, so a second pass hits nothing.
  PageTable thrashing(2);
  for (uint32_t page = 0; page < 8; ++page) thrashing.map(page, 0x1000 + page);
  for (int pass = 0; pass < 2; ++pass)
    for (uint32_t page = 0; page < 8; ++page) thrashing.translate(page << 12);
  assert(thrashing.statistics().tlb_hits == 0);
  assert(thrashing.statistics().tlb_misses == 16);

  // The same eight accesses with page locality: one miss then seven hits.
  PageTable local(2);
  local.map(0, 0x1000);
  for (int i = 0; i < 8; ++i) local.translate(i * 16);  // all inside page 0
  assert(local.statistics().tlb_misses == 1);
  assert(local.statistics().tlb_hits == 7);
  return 0;
}
