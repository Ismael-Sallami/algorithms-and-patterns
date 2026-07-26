// Pattern: Prefix sums
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check prefix_sums.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <vector>

using namespace std;

// Prefix sums turn any range-sum query into one subtraction. Build once in O(n),
// then every query is O(1) instead of O(n).
class PrefixSum {
  vector<long long> prefix;  // prefix[i] = sum of the first i elements

 public:
  explicit PrefixSum(const vector<int>& values) : prefix(values.size() + 1, 0) {
    for (size_t i = 0; i < values.size(); ++i) prefix[i + 1] = prefix[i] + values[i];
  }

  // Sum of values[from..to], both inclusive.
  long long range(size_t from, size_t to) const {
    assert(from <= to && to + 1 < prefix.size());
    return prefix[to + 1] - prefix[from];
  }
};

// Counts subarrays summing to target. A subarray sum is a difference of two prefix
// sums, so "does a subarray ending here sum to target" becomes "have I seen the
// prefix sum (current - target) before". A sliding window cannot do this, because
// negative values break the monotonicity a window depends on.
int count_subarrays_with_sum(const vector<int>& values, long long target) {
  unordered_map<long long, int> seen{{0, 1}};  // the empty prefix counts once
  long long running = 0;
  int total = 0;
  for (int value : values) {
    running += value;
    auto it = seen.find(running - target);
    if (it != seen.end()) total += it->second;
    ++seen[running];
  }
  return total;
}

int main() {
  PrefixSum sums({3, 1, 4, 1, 5, 9, 2, 6});
  assert(sums.range(0, 0) == 3);
  assert(sums.range(2, 4) == 10);
  assert(sums.range(0, 7) == 31);

  assert(count_subarrays_with_sum({1, 1, 1}, 2) == 2);
  assert(count_subarrays_with_sum({3, 4, 7, 2, -3, 1, 4, 2}, 7) == 4);
  // Negative values are exactly why a window does not work here.
  assert(count_subarrays_with_sum({1, -1, 0}, 0) == 3);
  return 0;
}
