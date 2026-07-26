// Pattern: Bitmask and interval dynamic programming
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check bitmask_and_interval_dp.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <climits>
#include <string>
#include <vector>

using namespace std;

// Two state shapes that are not a simple index.

// Travelling salesman by bitmask DP. The state is (set of visited cities, current city),
// so the table has n x 2^n entries and the cost is O(n^2 x 2^n).
//
// That is exponential, and it is still the point: brute force over permutations is O(n!),
// which is 3.6 million at n = 10 and 1.3 billion at n = 13, against 100 thousand and 1.4
// million here. Encoding the visited set as an integer works because once the current city
// is known, the order of the visit no longer matters - only the set does. Collapsing
// permutations into subsets is the whole saving.
long long travelling_salesman(const vector<vector<long long>>& distance) {
  const int n = static_cast<int>(distance.size());
  if (n <= 1) return 0;
  const int full = 1 << n;
  const long long unreachable = LLONG_MAX / 4;

  // best[visited][at] = cheapest route from city 0 covering `visited`, ending at `at`
  vector<vector<long long>> best(full, vector<long long>(n, unreachable));
  best[1][0] = 0;  // started at city 0, only city 0 visited

  for (int visited = 1; visited < full; ++visited)
    for (int at = 0; at < n; ++at) {
      if (best[visited][at] == unreachable) continue;
      if (!(visited & (1 << at))) continue;
      for (int next = 0; next < n; ++next) {
        if (visited & (1 << next)) continue;  // already been there
        const int after = visited | (1 << next);
        best[after][next] = min(best[after][next], best[visited][at] + distance[at][next]);
      }
    }

  long long shortest = unreachable;
  for (int last = 1; last < n; ++last)
    shortest = min(shortest, best[full - 1][last] + distance[last][0]);
  return shortest;
}

// Matrix chain multiplication. The state is an interval and the transition splits it at
// every possible point, so the loops run over interval length rather than position.
// Filling by increasing length is what guarantees both halves are already solved.
//
// The problem is choosing the parenthesisation: multiplying 10x100 by 100x5 by 5x50 costs
// 7500 operations one way and 75000 the other, for the same result.
long long matrix_chain_cost(const vector<int>& dimensions) {
  const size_t n = dimensions.size() - 1;  // n matrices, n+1 dimensions
  if (n < 2) return 0;
  vector<vector<long long>> best(n, vector<long long>(n, 0));

  for (size_t length = 2; length <= n; ++length)
    for (size_t from = 0; from + length - 1 < n; ++from) {
      const size_t to = from + length - 1;
      best[from][to] = LLONG_MAX;
      for (size_t split = from; split < to; ++split) {
        const long long cost = best[from][split] + best[split + 1][to] +
                               static_cast<long long>(dimensions[from]) *
                                   dimensions[split + 1] * dimensions[to + 1];
        best[from][to] = min(best[from][to], cost);
      }
    }
  return best[0][n - 1];
}

// Longest palindromic subsequence: interval DP where the transition compares the ends.
size_t longest_palindromic_subsequence(const string& text) {
  const size_t n = text.size();
  if (n == 0) return 0;
  vector<vector<size_t>> best(n, vector<size_t>(n, 0));
  for (size_t i = 0; i < n; ++i) best[i][i] = 1;

  for (size_t length = 2; length <= n; ++length)
    for (size_t from = 0; from + length - 1 < n; ++from) {
      const size_t to = from + length - 1;
      if (text[from] == text[to])
        best[from][to] = (length == 2) ? 2 : best[from + 1][to - 1] + 2;
      else
        best[from][to] = max(best[from + 1][to], best[from][to - 1]);
    }
  return best[0][n - 1];
}

int main() {
  // A square: the optimal tour is the perimeter, cost 4.
  const long long big = 1000;
  assert(travelling_salesman({{0, 1, big, 1},
                              {1, 0, 1, big},
                              {big, 1, 0, 1},
                              {1, big, 1, 0}}) == 4);
  assert(travelling_salesman({{0, 7}, {7, 0}}) == 14);  // out and back
  assert(travelling_salesman({{0}}) == 0);

  // A symmetric instance with a known answer of 80.
  assert(travelling_salesman({{0, 10, 15, 20},
                              {10, 0, 35, 25},
                              {15, 35, 0, 30},
                              {20, 25, 30, 0}}) == 80);

  assert(matrix_chain_cost({10, 100, 5, 50}) == 7500);
  assert(matrix_chain_cost({40, 20, 30, 10, 30}) == 26000);
  assert(matrix_chain_cost({10, 20}) == 0);  // one matrix, nothing to choose

  assert(longest_palindromic_subsequence("bbbab") == 4);  // bbbb
  assert(longest_palindromic_subsequence("cbbd") == 2);   // bb
  assert(longest_palindromic_subsequence("abc") == 1);
  assert(longest_palindromic_subsequence("") == 0);
  assert(longest_palindromic_subsequence("racecar") == 7);
  return 0;
}
