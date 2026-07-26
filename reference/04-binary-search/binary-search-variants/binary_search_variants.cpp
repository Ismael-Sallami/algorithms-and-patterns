// Pattern: Binary search variants
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check binary_search_variants.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

// Binary search comes down to maintaining one invariant and never breaking it. The two
// bounds below are written as half-open [low, high) searches: the loop ends when the range
// is empty and `low` is the answer, so there is no separate found/not-found branch and no
// off-by-one at the edges.

// First index whose value is >= target (std::lower_bound).
size_t lower_bound_index(const vector<int>& sorted, int target) {
  size_t low = 0, high = sorted.size();
  while (low < high) {
    const size_t mid = low + (high - low) / 2;  // written this way to avoid overflow
    if (sorted[mid] < target) low = mid + 1;
    else high = mid;
  }
  return low;
}

// First index whose value is > target (std::upper_bound).
size_t upper_bound_index(const vector<int>& sorted, int target) {
  size_t low = 0, high = sorted.size();
  while (low < high) {
    const size_t mid = low + (high - low) / 2;
    if (sorted[mid] <= target) low = mid + 1;
    else high = mid;
  }
  return low;
}

// The two bounds together give the count of a value, which is why they are worth having
// instead of a plain "find".
size_t count_of(const vector<int>& sorted, int target) {
  return upper_bound_index(sorted, target) - lower_bound_index(sorted, target);
}

// Search in a sorted array rotated at an unknown pivot. At least one half of the range is
// always still sorted; comparing the midpoint to the low end says which, and a sorted half
// can be tested for containment in O(1).
int search_rotated(const vector<int>& values, int target) {
  int low = 0, high = static_cast<int>(values.size()) - 1;
  while (low <= high) {
    const int mid = low + (high - low) / 2;
    if (values[mid] == target) return mid;
    if (values[low] <= values[mid]) {  // left half sorted
      if (values[low] <= target && target < values[mid]) high = mid - 1;
      else low = mid + 1;
    } else {                           // right half sorted
      if (values[mid] < target && target <= values[high]) low = mid + 1;
      else high = mid - 1;
    }
  }
  return -1;
}

// Binary search does not need a sorted array. It needs a monotone predicate: a threshold
// below which the answer is always no and above which always yes. Then the search runs over
// the answer space, not over the data.
//
// Smallest ship capacity that moves all packages within `days`, keeping order. Feasibility
// is monotone: if a capacity works, any larger one works too.
static int days_needed(const vector<int>& weights, int capacity) {
  int days = 1, load = 0;
  for (int weight : weights) {
    if (load + weight > capacity) { ++days; load = 0; }
    load += weight;
  }
  return days;
}

int least_capacity(const vector<int>& weights, int days) {
  // Lower bound: no single package can be split. Upper bound: carry everything at once.
  int low = *max_element(weights.begin(), weights.end());
  int high = 0;
  for (int weight : weights) high += weight;

  while (low < high) {
    const int mid = low + (high - low) / 2;
    if (days_needed(weights, mid) <= days) high = mid;
    else low = mid + 1;
  }
  return low;
}

// Integer square root by the same shape of search. The multiplication is avoided entirely -
// `mid <= value / mid` rather than `mid * mid <= value` - because that product is where
// this overflows in practice.
long long integer_sqrt(long long value) {
  if (value < 0) return -1;
  long long low = 0, high = value;
  while (low < high) {
    const long long mid = low + (high - low + 1) / 2;  // upper mid: converges to the floor
    if (mid <= value / mid) low = mid;
    else high = mid - 1;
  }
  return low;
}

int main() {
  const vector<int> sorted = {1, 2, 2, 2, 5, 8};
  assert(lower_bound_index(sorted, 2) == 1);
  assert(upper_bound_index(sorted, 2) == 4);
  assert(count_of(sorted, 2) == 3);
  assert(count_of(sorted, 3) == 0);
  // Off both ends, and the empty array: the half-open form needs no special case.
  assert(lower_bound_index(sorted, 0) == 0);
  assert(lower_bound_index(sorted, 99) == sorted.size());
  assert(lower_bound_index({}, 5) == 0);

  assert(search_rotated({4, 5, 6, 7, 0, 1, 2}, 0) == 4);
  assert(search_rotated({4, 5, 6, 7, 0, 1, 2}, 3) == -1);
  assert(search_rotated({1}, 1) == 0);
  assert(search_rotated({3, 1}, 1) == 1);

  assert(least_capacity({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 5) == 15);
  assert(least_capacity({3, 2, 2, 4, 1, 4}, 3) == 6);
  // One day: the whole load. As many days as packages: the heaviest one.
  assert(least_capacity({1, 2, 3}, 1) == 6);
  assert(least_capacity({1, 2, 3}, 3) == 3);

  assert(integer_sqrt(0) == 0 && integer_sqrt(1) == 1);
  assert(integer_sqrt(8) == 2 && integer_sqrt(9) == 3);
  assert(integer_sqrt(2147395600LL) == 46340);
  // Would overflow a 32-bit mid*mid.
  assert(integer_sqrt(4611686014132420609LL) == 2147483647LL);
  return 0;
}
