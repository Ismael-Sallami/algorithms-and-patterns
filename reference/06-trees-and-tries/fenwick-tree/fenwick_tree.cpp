// Pattern: Fenwick tree
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check fenwick_tree.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

// A Fenwick tree (binary indexed tree) does prefix sums with point updates in O(log n),
// like a segment tree, in half the space and a fraction of the code.
//
// It works because every index covers a range whose length is its lowest set bit.
// Stripping that bit walks down the prefix decomposition; adding it walks up the indices a
// position contributes to. The whole structure is those two operations. The trade against
// a segment tree is that it only handles invertible operations - sums, not minima.
class FenwickTree {
  vector<long long> tree;  // 1-indexed

  static size_t lowest_bit(size_t i) { return i & (~i + 1); }

 public:
  explicit FenwickTree(size_t size) : tree(size + 1, 0) {}

  explicit FenwickTree(const vector<int>& values) : tree(values.size() + 1, 0) {
    for (size_t i = 0; i < values.size(); ++i) add(i, values[i]);
  }

  void add(size_t index, long long delta) {
    for (size_t i = index + 1; i < tree.size(); i += lowest_bit(i)) tree[i] += delta;
  }

  long long prefix_sum(size_t count) const {
    long long total = 0;
    for (size_t i = count; i > 0; i -= lowest_bit(i)) total += tree[i];
    return total;
  }

  // Invertibility is what makes this a subtraction.
  long long range_sum(size_t from, size_t to) const {
    return prefix_sum(to) - prefix_sum(from);
  }
};

// Counting inversions: pairs out of order. Processing right to left and asking how many
// already-seen values are smaller turns an O(n^2) count into O(n log n).
long long count_inversions(const vector<int>& values, int max_value) {
  FenwickTree seen(static_cast<size_t>(max_value) + 1);
  long long inversions = 0;
  for (size_t i = values.size(); i-- > 0;) {
    inversions += seen.prefix_sum(static_cast<size_t>(values[i]));
    seen.add(static_cast<size_t>(values[i]), 1);
  }
  return inversions;
}

int main() {
  FenwickTree tree({1, 2, 3, 4, 5});
  assert(tree.prefix_sum(5) == 15);
  assert(tree.prefix_sum(0) == 0);
  assert(tree.range_sum(1, 4) == 9);

  tree.add(2, 10);  // the third element, 3 -> 13
  assert(tree.prefix_sum(5) == 25);
  assert(tree.range_sum(2, 3) == 13);

  assert(count_inversions({1, 2, 3}, 3) == 0);  // already sorted
  assert(count_inversions({3, 2, 1}, 3) == 3);  // fully reversed
  assert(count_inversions({2, 4, 1, 3, 5}, 5) == 3);
  assert(count_inversions({1, 1, 1}, 1) == 0);  // equal values are not inversions
  return 0;
}
