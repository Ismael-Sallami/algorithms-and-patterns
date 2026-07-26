// Pattern: One-dimensional dynamic programming
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check one_dimensional_dp.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <climits>
#include <vector>

using namespace std;

// Four steps turn a recurrence into a table: identify the state, write the transition,
// order the states so dependencies come first, and decide how much of the table has to be
// kept. That last step is where most of the space savings live.

// Fibonacci, to make the progression explicit. Naive recursion recomputes the same
// subproblems exponentially often; memoising makes it linear; tabulating removes the
// recursion; noticing that only two previous values are read drops the space to O(1). The
// recurrence never changed - only what is stored.
long long fibonacci_memo(int n, vector<long long>& cache) {
  if (n <= 1) return n;
  if (cache[n] != -1) return cache[n];
  return cache[n] = fibonacci_memo(n - 1, cache) + fibonacci_memo(n - 2, cache);
}

long long fibonacci_rolling(int n) {
  if (n <= 1) return n;
  long long previous = 0, current = 1;
  for (int i = 2; i <= n; ++i) {
    const long long next = previous + current;
    previous = current;
    current = next;
  }
  return current;
}

// Maximum subarray sum (Kadane). The state is "best sum ending here" and the transition is
// one choice: extend the previous run or start a new one. Initialising from the first
// element rather than zero is what makes an all-negative input work.
long long max_subarray_sum(const vector<int>& values) {
  long long best = values[0], ending_here = values[0];
  for (size_t i = 1; i < values.size(); ++i) {
    ending_here = max<long long>(values[i], ending_here + values[i]);
    best = max(best, ending_here);
  }
  return best;
}

// Maximum sum with no two adjacent elements. Two states per position - take it or skip it -
// collapsed into two rolling variables.
long long max_non_adjacent_sum(const vector<int>& values) {
  long long take = 0, skip = 0;
  for (int value : values) {
    const long long new_take = skip + value;  // taking requires having skipped
    skip = max(skip, take);
    take = new_take;
  }
  return max(take, skip);
}

// Longest increasing subsequence in O(n log n).
//
// The O(n^2) version compares every pair. This keeps tails[k] = the smallest value that
// can end an increasing subsequence of length k+1. That array is sorted by construction,
// so each new value is placed by binary search. The array is not itself a valid
// subsequence - only its length is the answer.
size_t longest_increasing_subsequence(const vector<int>& values) {
  vector<int> tails;
  for (int value : values) {
    auto position = lower_bound(tails.begin(), tails.end(), value);
    if (position == tails.end()) tails.push_back(value);
    else *position = value;  // a smaller tail leaves more room for what follows
  }
  return tails.size();
}

// Fewest coins making the amount, or -1. Unbounded supply, so the inner loop runs forwards
// and a coin can be reused within one pass.
int fewest_coins(const vector<int>& coins, int amount) {
  vector<int> best(amount + 1, INT_MAX);
  best[0] = 0;
  for (int value = 1; value <= amount; ++value)
    for (int coin : coins) {
      if (coin > value || best[value - coin] == INT_MAX) continue;
      best[value] = min(best[value], best[value - coin] + 1);
    }
  return best[amount] == INT_MAX ? -1 : best[amount];
}

int main() {
  vector<long long> cache(51, -1);
  assert(fibonacci_memo(50, cache) == 12586269025LL);
  assert(fibonacci_rolling(50) == 12586269025LL);
  assert(fibonacci_rolling(0) == 0 && fibonacci_rolling(1) == 1);

  assert(max_subarray_sum({-2, 1, -3, 4, -1, 2, 1, -5, 4}) == 6);
  assert(max_subarray_sum({1}) == 1);
  // All negative: the answer is the least bad single element, not zero.
  assert(max_subarray_sum({-5, -2, -9}) == -2);

  assert(max_non_adjacent_sum({2, 7, 9, 3, 1}) == 12);  // 2 + 9 + 1
  assert(max_non_adjacent_sum({5}) == 5);
  assert(max_non_adjacent_sum({}) == 0);
  assert(max_non_adjacent_sum({2, 1, 1, 2}) == 4);  // the ends, not the middle

  assert(longest_increasing_subsequence({10, 9, 2, 5, 3, 7, 101, 18}) == 4);
  assert(longest_increasing_subsequence({7, 7, 7}) == 1);  // strictly increasing
  assert(longest_increasing_subsequence({}) == 0);

  assert(fewest_coins({1, 5, 10, 25}, 63) == 6);  // 25+25+10+1+1+1
  assert(fewest_coins({2}, 3) == -1);             // unreachable
  assert(fewest_coins({1, 5, 10}, 0) == 0);
  // Greedy fails here and DP does not: 6+6+3 beats 7 followed by six ones.
  assert(fewest_coins({1, 3, 6, 7}, 15) == 3);
  return 0;
}
