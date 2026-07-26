// Pattern: LRU cache
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check lru_cache.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <list>
#include <unordered_map>

using namespace std;

// Fixed-capacity cache evicting the least recently used entry, O(1) per operation.
//
// Neither structure alone is enough: a hash map gives O(1) lookup and no order, a list
// gives order and O(n) lookup. Combining them - the map stores an iterator into the list -
// makes both constant. std::list is what makes it work: splice moves a node without
// invalidating iterators to it, so the map never needs updating on a promotion.
class LRUCache {
  size_t capacity;
  list<pair<int, int>> entries;  // front = newest
  unordered_map<int, list<pair<int, int>>::iterator> positions;

 public:
  explicit LRUCache(size_t capacity) : capacity(capacity) {}

  // Returns true and writes the value if present, promoting it to newest.
  bool get(int key, int& value) {
    auto it = positions.find(key);
    if (it == positions.end()) return false;
    entries.splice(entries.begin(), entries, it->second);  // the iterator stays valid
    value = it->second->second;
    return true;
  }

  void put(int key, int value) {
    auto it = positions.find(key);
    if (it != positions.end()) {
      it->second->second = value;
      entries.splice(entries.begin(), entries, it->second);
      return;
    }
    if (entries.size() == capacity) {
      positions.erase(entries.back().first);
      entries.pop_back();
    }
    entries.emplace_front(key, value);
    positions[key] = entries.begin();
  }

  size_t size() const { return entries.size(); }
};

int main() {
  LRUCache cache(2);
  int value = 0;

  cache.put(1, 100);
  cache.put(2, 200);
  // Reading 1 makes it newest, so 2 becomes the next eviction.
  assert(cache.get(1, value) && value == 100);

  cache.put(3, 300);  // evicts 2
  assert(!cache.get(2, value));
  assert(cache.get(1, value) && value == 100);
  assert(cache.get(3, value) && value == 300);

  cache.put(1, 111);  // overwrite, not insert
  assert(cache.size() == 2);
  assert(cache.get(1, value) && value == 111);

  // Capacity one: every insert evicts.
  LRUCache tiny(1);
  tiny.put(1, 1);
  tiny.put(2, 2);
  assert(!tiny.get(1, value));
  assert(tiny.get(2, value) && value == 2);
  return 0;
}
