// Pattern: Segment tree
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check segment_tree.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <climits>
#include <vector>

using namespace std;

// Range queries with point updates. A prefix-sum array gives O(1) queries and O(n)
// updates; a plain scan gives O(1) updates and O(n) queries. A segment tree makes both
// O(log n), which is the right trade when updates and queries are interleaved.
//
// Written iteratively over a 1-indexed array of size 2n: leaves live at [n, 2n) and a
// node's parent is at i/2. No recursion and no child pointers.
class SegmentTree {
  size_t n;
  vector<long long> tree;

 public:
  explicit SegmentTree(const vector<int>& values)
      : n(values.size()), tree(2 * values.size(), 0) {
    for (size_t i = 0; i < n; ++i) tree[n + i] = values[i];
    for (size_t i = n - 1; i >= 1; --i) tree[i] = tree[2 * i] + tree[2 * i + 1];
  }

  void set(size_t index, long long value) {
    size_t i = index + n;
    tree[i] = value;
    for (i /= 2; i >= 1; i /= 2) tree[i] = tree[2 * i] + tree[2 * i + 1];
  }

  // Sum over [from, to). Walks up from both ends, taking a node whenever it sits on the
  // outside of its parent - which is exactly when the parent would overrun the query.
  long long sum(size_t from, size_t to) const {
    long long total = 0;
    for (size_t low = from + n, high = to + n; low < high; low /= 2, high /= 2) {
      if (low & 1) total += tree[low++];
      if (high & 1) total += tree[--high];
    }
    return total;
  }
};

// The same structure with min instead of sum. Any associative operation with an identity
// works; that is the whole abstraction.
class MinTree {
  size_t n;
  vector<int> tree;

 public:
  explicit MinTree(const vector<int>& values)
      : n(values.size()), tree(2 * values.size(), INT_MAX) {
    for (size_t i = 0; i < n; ++i) tree[n + i] = values[i];
    for (size_t i = n - 1; i >= 1; --i) tree[i] = min(tree[2 * i], tree[2 * i + 1]);
  }

  int minimum(size_t from, size_t to) const {
    int best = INT_MAX;
    for (size_t low = from + n, high = to + n; low < high; low /= 2, high /= 2) {
      if (low & 1) best = min(best, tree[low++]);
      if (high & 1) best = min(best, tree[--high]);
    }
    return best;
  }
};

int main() {
  SegmentTree sums({1, 3, 5, 7, 9, 11});
  assert(sums.sum(0, 6) == 36);
  assert(sums.sum(1, 3) == 8);
  assert(sums.sum(2, 3) == 5);
  assert(sums.sum(3, 3) == 0);  // empty range

  sums.set(1, 10);  // 3 -> 10
  assert(sums.sum(0, 6) == 43);
  assert(sums.sum(1, 3) == 15);

  MinTree minima({5, 2, 8, 1, 9});
  assert(minima.minimum(0, 5) == 1);
  assert(minima.minimum(0, 3) == 2);
  assert(minima.minimum(2, 3) == 8);
  return 0;
}
