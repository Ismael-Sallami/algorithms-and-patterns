// Pattern: Binary heap
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check binary_heap.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <vector>

using namespace std;

// A binary min-heap over a flat array. The tree is implicit: the children of i are at
// 2i+1 and 2i+2, so there are no pointers and the layout is contiguous.
//
// The invariant is local - every parent is no greater than its children - which is weaker
// than sorting and therefore cheaper to restore. That weaker invariant is exactly enough
// to know where the minimum is.
class MinHeap {
  vector<int> data;

  void sift_up(size_t i) {
    while (i > 0) {
      const size_t parent = (i - 1) / 2;
      if (data[parent] <= data[i]) break;
      swap(data[parent], data[i]);
      i = parent;
    }
  }

  void sift_down(size_t i) {
    const size_t n = data.size();
    for (;;) {
      const size_t left = 2 * i + 1, right = 2 * i + 2;
      size_t smallest = i;
      if (left < n && data[left] < data[smallest]) smallest = left;
      if (right < n && data[right] < data[smallest]) smallest = right;
      if (smallest == i) break;
      swap(data[i], data[smallest]);
      i = smallest;
    }
  }

 public:
  MinHeap() = default;

  // Heapify in O(n), not O(n log n). Sifting down from the last internal node upwards
  // works because the leaves are already valid heaps, and the cost is bounded by the sum
  // of subtree heights, which is linear.
  explicit MinHeap(vector<int> values) : data(move(values)) {
    if (data.size() < 2) return;
    for (size_t i = data.size() / 2; i-- > 0;) sift_down(i);
  }

  void push(int value) {
    data.push_back(value);
    sift_up(data.size() - 1);
  }

  int top() const {
    if (data.empty()) throw out_of_range("top of empty heap");
    return data[0];
  }

  int pop() {
    if (data.empty()) throw out_of_range("pop from empty heap");
    const int smallest = data[0];
    data[0] = data.back();
    data.pop_back();
    if (!data.empty()) sift_down(0);
    return smallest;
  }

  bool empty() const { return data.empty(); }
  size_t size() const { return data.size(); }
};

// Heapsort: build a max-heap in place, then repeatedly move the root to the end and shrink
// the heap. O(n log n) worst case unlike quicksort, and O(1) extra space unlike merge sort.
// What it gives up is stability and cache locality, which is why library sorts prefer a
// quicksort hybrid and keep heapsort as the fallback that guarantees the bound.
static void sift_down_max(vector<int>& values, size_t root, size_t heap_size) {
  for (;;) {
    const size_t left = 2 * root + 1, right = 2 * root + 2;
    size_t largest = root;
    if (left < heap_size && values[left] > values[largest]) largest = left;
    if (right < heap_size && values[right] > values[largest]) largest = right;
    if (largest == root) return;
    swap(values[root], values[largest]);
    root = largest;
  }
}

void heapsort(vector<int>& values) {
  const size_t n = values.size();
  if (n < 2) return;
  for (size_t i = n / 2; i-- > 0;) sift_down_max(values, i, n);  // build, O(n)
  for (size_t end = n; end-- > 1;) {                             // drain, O(n log n)
    swap(values[0], values[end]);
    sift_down_max(values, 0, end);
  }
}

int main() {
  MinHeap heap;
  for (int value : {5, 3, 8, 1, 9, 2}) heap.push(value);
  assert(heap.size() == 6 && heap.top() == 1);

  vector<int> drained;
  while (!heap.empty()) drained.push_back(heap.pop());
  assert(is_sorted(drained.begin(), drained.end()));
  assert(drained == vector<int>({1, 2, 3, 5, 8, 9}));

  // Linear-time construction must produce the same order as repeated pushes.
  MinHeap built({7, 7, 1, 4, 4, 9, 0});
  vector<int> from_build;
  while (!built.empty()) from_build.push_back(built.pop());
  assert(from_build == vector<int>({0, 1, 4, 4, 7, 7, 9}));

  MinHeap empty_heap;
  bool threw = false;
  try { empty_heap.pop(); } catch (const out_of_range&) { threw = true; }
  assert(threw);

  vector<int> values = {5, 3, 8, 1, 9, 2, 7};
  heapsort(values);
  assert(values == vector<int>({1, 2, 3, 5, 7, 8, 9}));
  vector<int> duplicates = {2, 2, 1, 2};
  heapsort(duplicates);
  assert(duplicates == vector<int>({1, 2, 2, 2}));
  vector<int> none;
  heapsort(none);
  assert(none.empty());
  return 0;
}
