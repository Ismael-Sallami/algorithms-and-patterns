// Pattern: Two pointer pair sum
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check two_pointer_pair_sum.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

// Finds a pair summing to target in a sorted array. Two indices walking inwards: if
// the sum is too small only moving the left pointer helps, if too large only moving
// the right one does. Every step eliminates a whole row or column of the pair space,
// which is why one pass replaces the O(n^2) scan.
pair<int, int> pair_with_sum(const vector<int>& sorted, long long target) {
  int left = 0, right = static_cast<int>(sorted.size()) - 1;
  while (left < right) {
    const long long sum = static_cast<long long>(sorted[left]) + sorted[right];
    if (sum == target) return {left, right};
    if (sum < target) ++left;
    else --right;
  }
  return {-1, -1};
}

// All unique triplets summing to zero. Fix one element, two-pointer the rest. Sorting
// first is what makes both the scan and the duplicate skipping possible.
vector<vector<int>> triplets_summing_to_zero(vector<int> values) {
  sort(values.begin(), values.end());
  vector<vector<int>> result;
  const int n = static_cast<int>(values.size());

  for (int i = 0; i + 2 < n; ++i) {
    if (values[i] > 0) break;                            // no way back to zero
    if (i > 0 && values[i] == values[i - 1]) continue;    // same first element
    int left = i + 1, right = n - 1;
    while (left < right) {
      const int sum = values[i] + values[left] + values[right];
      if (sum < 0) { ++left; continue; }
      if (sum > 0) { --right; continue; }
      result.push_back({values[i], values[left], values[right]});
      while (left < right && values[left] == values[left + 1]) ++left;
      while (left < right && values[right] == values[right - 1]) --right;
      ++left;
      --right;
    }
  }
  return result;
}

int main() {
  assert(pair_with_sum({1, 3, 4, 5, 7, 11}, 9) == make_pair(2, 3));
  assert(pair_with_sum({1, 2}, 100) == make_pair(-1, -1));

  vector<vector<int>> t = triplets_summing_to_zero({-1, 0, 1, 2, -1, -4});
  assert(t.size() == 2);
  assert(t[0] == vector<int>({-1, -1, 2}));
  assert(t[1] == vector<int>({-1, 0, 1}));
  // All zeros: exactly one triplet, not C(n,3) of them.
  assert(triplets_summing_to_zero({0, 0, 0, 0}).size() == 1);
  assert(triplets_summing_to_zero({1, 2, 3}).empty());
  return 0;
}
