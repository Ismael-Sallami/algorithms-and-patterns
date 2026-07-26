// Pattern: Cyclic sort and missing values
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check cyclic_sort_and_missing_values.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

// When values are a permutation of 1..n, the array can index itself: value v belongs
// at position v-1. Placing each value where it belongs takes O(n) overall, because
// every swap puts one value in its final place, and a single scan then reveals what
// is missing or duplicated. No hash set and no extra allocation.
void cyclic_sort(vector<int>& values) {
  size_t i = 0;
  while (i < values.size()) {
    const size_t target = static_cast<size_t>(values[i]) - 1;
    if (target < values.size() && values[i] != values[target]) swap(values[i], values[target]);
    else ++i;
  }
}

// First missing positive integer in O(n) time and O(1) extra space. The answer is
// always in 1..n+1, so anything outside that range is irrelevant and the array itself
// serves as the marker structure.
//
// The swap condition compares values rather than positions, which is what stops
// duplicates from sending the loop spinning forever.
int first_missing_positive(vector<int> values) {
  const int n = static_cast<int>(values.size());
  for (int i = 0; i < n;) {
    const int target = values[i] - 1;
    if (target >= 0 && target < n && values[i] != values[target]) swap(values[i], values[target]);
    else ++i;
  }
  for (int i = 0; i < n; ++i)
    if (values[i] != i + 1) return i + 1;
  return n + 1;
}

int main() {
  vector<int> values = {3, 1, 5, 4, 2};
  cyclic_sort(values);
  assert(values == vector<int>({1, 2, 3, 4, 5}));

  assert(first_missing_positive({1, 2, 0}) == 3);
  assert(first_missing_positive({3, 4, -1, 1}) == 2);
  assert(first_missing_positive({7, 8, 9, 11, 12}) == 1);
  // A full permutation: the answer is n+1.
  assert(first_missing_positive({1, 2, 3}) == 4);
  assert(first_missing_positive({1, 1}) == 2);
  return 0;
}
