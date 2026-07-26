// Pattern: Sliding window variable size
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check sliding_window_variable_size.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Longest substring with no repeated character. The window is valid when it holds no
// duplicate; on a repeat the left edge jumps straight past the previous occurrence
// rather than sliding one step at a time. That jump keeps the total at O(n), because
// each index is visited once by each pointer.
int longest_unique_substring(const string& text) {
  unordered_map<char, int> last_seen;
  int best = 0, left = 0;
  for (int right = 0; right < static_cast<int>(text.size()); ++right) {
    auto it = last_seen.find(text[right]);
    // The guard on `left` is what stops the edge jumping backwards.
    if (it != last_seen.end() && it->second >= left) left = it->second + 1;
    last_seen[text[right]] = right;
    best = max(best, right - left + 1);
  }
  return best;
}

// Shortest subarray whose sum reaches target. Grow on the right until valid, then
// shrink from the left while it stays valid. Correct only for non-negative values:
// with negatives, shrinking can increase the sum and the window stops being
// monotone, which is where prefix sums plus a hash map take over.
int shortest_subarray_at_least(const vector<int>& values, long long target) {
  long long window = 0;
  int best = -1, left = 0;
  for (int right = 0; right < static_cast<int>(values.size()); ++right) {
    window += values[right];
    while (window >= target) {
      const int width = right - left + 1;
      if (best == -1 || width < best) best = width;
      window -= values[left++];
    }
  }
  return best;
}

// Maximum sum over a window of exactly k: add the entering element, remove the
// leaving one. No inner loop, so O(n) instead of O(n*k).
long long max_fixed_window_sum(const vector<int>& values, int k) {
  if (static_cast<int>(values.size()) < k || k <= 0) return 0;
  long long window = 0;
  for (int i = 0; i < k; ++i) window += values[i];
  long long best = window;
  for (int i = k; i < static_cast<int>(values.size()); ++i) {
    window += values[i] - values[i - k];
    best = max(best, window);
  }
  return best;
}

int main() {
  assert(longest_unique_substring("abcabcbb") == 3);
  assert(longest_unique_substring("bbbbb") == 1);
  assert(longest_unique_substring("pwwkew") == 3);
  assert(longest_unique_substring("") == 0);
  // The left edge must not move backwards on the second 't'.
  assert(longest_unique_substring("tmmzuxt") == 5);

  assert(shortest_subarray_at_least({2, 3, 1, 2, 4, 3}, 7) == 2);
  assert(shortest_subarray_at_least({1, 1, 1}, 100) == -1);
  assert(max_fixed_window_sum({1, 12, -5, -6, 50, 3}, 4) == 51);
  return 0;
}
