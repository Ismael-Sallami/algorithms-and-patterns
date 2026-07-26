// Pattern: Container with most water
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check container_with_most_water.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

// Largest rectangle between two of n vertical lines.
//
// Area is distance times the shorter line. Starting from the widest pair, moving the
// taller line inwards can never help: the width shrinks and the height is still
// capped by the shorter line. So only the shorter one is worth moving, and that
// discards a candidate per step - O(n) instead of the O(n^2) pair scan.
long long max_water_area(const vector<int>& heights) {
  int left = 0, right = static_cast<int>(heights.size()) - 1;
  long long best = 0;
  while (left < right) {
    const long long height = min(heights[left], heights[right]);
    best = max(best, height * (right - left));
    if (heights[left] < heights[right]) ++left;
    else --right;
  }
  return best;
}

// Rainwater trapped above a height profile. The water over a column is the smaller of
// the tallest wall on each side, minus the column. Tracking both running maxima while
// closing in from the ends gives it in one pass with no auxiliary arrays.
long long trapped_water(const vector<int>& heights) {
  if (heights.size() < 3) return 0;
  int left = 0, right = static_cast<int>(heights.size()) - 1;
  int left_max = heights[left], right_max = heights[right];
  long long total = 0;
  while (left < right) {
    if (left_max <= right_max) {
      ++left;
      left_max = max(left_max, heights[left]);
      total += left_max - heights[left];
    } else {
      --right;
      right_max = max(right_max, heights[right]);
      total += right_max - heights[right];
    }
  }
  return total;
}

int main() {
  assert(max_water_area({1, 8, 6, 2, 5, 4, 8, 3, 7}) == 49);
  assert(max_water_area({1, 1}) == 1);

  assert(trapped_water({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) == 6);
  assert(trapped_water({4, 2, 0, 3, 2, 5}) == 9);
  // Monotone profiles hold nothing.
  assert(trapped_water({1, 2, 3, 4}) == 0);
  assert(trapped_water({4, 3, 2, 1}) == 0);
  return 0;
}
