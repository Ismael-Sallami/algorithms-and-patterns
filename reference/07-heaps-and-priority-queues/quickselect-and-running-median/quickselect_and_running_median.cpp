// Pattern: Quickselect and running median
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check quickselect_and_running_median.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <queue>
#include <random>
#include <vector>

using namespace std;

// The k-th smallest element without sorting.
//
// Sorting is O(n log n) and computes far more than asked. Quickselect partitions and then
// recurses into one side only, so the expected cost is O(n): n + n/2 + n/4 + ... The worst
// case is O(n^2) on an adversarial pivot sequence, which is why the pivot is chosen at
// random rather than taken from a fixed position.
static mt19937 rng(12345);  // fixed seed so the test is reproducible

static size_t partition_around(vector<int>& values, size_t low, size_t high) {
  uniform_int_distribution<size_t> pick(low, high);
  swap(values[pick(rng)], values[high]);
  const int pivot = values[high];
  size_t boundary = low;
  for (size_t i = low; i < high; ++i)
    if (values[i] < pivot) swap(values[i], values[boundary++]);
  swap(values[boundary], values[high]);
  return boundary;
}

// k is 0-based. Iterative rather than recursive: the recursion is a tail call, so the loop
// costs nothing and removes the stack depth entirely.
int kth_smallest(vector<int> values, size_t k) {
  size_t low = 0, high = values.size() - 1;
  for (;;) {
    if (low == high) return values[low];
    const size_t pivot = partition_around(values, low, high);
    if (k == pivot) return values[pivot];
    if (k < pivot) high = pivot - 1;
    else low = pivot + 1;
  }
}

// Median of a stream, O(log n) per insert and O(1) per query.
//
// Two heaps split the data at the median: a max-heap of the lower half and a min-heap of
// the upper half. The median then sits at one or both of the two tops. Keeping the sizes
// within one of each other is what makes that true, and it is the only invariant to
// maintain.
class RunningMedian {
  priority_queue<int> lower;                             // max-heap
  priority_queue<int, vector<int>, greater<int>> upper;   // min-heap

 public:
  void add(int value) {
    // Route through `lower` first and move its top across, which guarantees the ordering
    // between the halves is never broken, then rebalance the sizes.
    lower.push(value);
    upper.push(lower.top());
    lower.pop();
    if (upper.size() > lower.size()) {
      lower.push(upper.top());
      upper.pop();
    }
  }

  double median() const {
    if (lower.empty()) return 0.0;
    if (lower.size() > upper.size()) return static_cast<double>(lower.top());
    return (static_cast<double>(lower.top()) + static_cast<double>(upper.top())) / 2.0;
  }

  size_t size() const { return lower.size() + upper.size(); }
};

int main() {
  vector<int> values = {7, 10, 4, 3, 20, 15};
  assert(kth_smallest(values, 0) == 3);
  assert(kth_smallest(values, 2) == 7);
  assert(kth_smallest(values, 5) == 20);
  assert(kth_smallest({2, 2, 2}, 1) == 2);  // duplicates count
  assert(kth_smallest({42}, 0) == 42);

  // Every k against a sorted reference, so no index is left untested.
  vector<int> data = {9, 1, 8, 2, 7, 3, 6, 4, 5, 5};
  vector<int> reference = data;
  sort(reference.begin(), reference.end());
  for (size_t k = 0; k < data.size(); ++k) assert(kth_smallest(data, k) == reference[k]);

  RunningMedian stream;
  stream.add(1);
  assert(stream.median() == 1.0);
  stream.add(2);
  assert(stream.median() == 1.5);
  stream.add(3);
  assert(stream.median() == 2.0);
  stream.add(4);
  assert(stream.median() == 2.5);

  // Descending input exercises the rebalance on every insert.
  RunningMedian descending;
  for (int value : {5, 4, 3, 2, 1}) descending.add(value);
  assert(descending.median() == 3.0);
  assert(descending.size() == 5);
  return 0;
}
