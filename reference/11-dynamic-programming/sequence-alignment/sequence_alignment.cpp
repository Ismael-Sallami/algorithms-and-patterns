// Pattern: Sequence alignment
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check sequence_alignment.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

// Two-dimensional DP over a pair of sequences. The state is a pair of prefix lengths, and
// every transition consumes at least one character from one side, which is what makes the
// table acyclic and fills it in row order.
size_t longest_common_subsequence(const string& a, const string& b) {
  const size_t n = a.size(), m = b.size();
  vector<vector<size_t>> best(n + 1, vector<size_t>(m + 1, 0));
  for (size_t i = 1; i <= n; ++i)
    for (size_t j = 1; j <= m; ++j)
      best[i][j] = (a[i - 1] == b[j - 1]) ? best[i - 1][j - 1] + 1
                                          : max(best[i - 1][j], best[i][j - 1]);
  return best[n][m];
}

// The subsequence itself, recovered by walking the table backwards from the corner. The
// table already records which choice was best at every cell, so the traceback reads it off
// with no extra bookkeeping.
string lcs_string(const string& a, const string& b) {
  const size_t n = a.size(), m = b.size();
  vector<vector<size_t>> best(n + 1, vector<size_t>(m + 1, 0));
  for (size_t i = 1; i <= n; ++i)
    for (size_t j = 1; j <= m; ++j)
      best[i][j] = (a[i - 1] == b[j - 1]) ? best[i - 1][j - 1] + 1
                                          : max(best[i - 1][j], best[i][j - 1]);

  string out;
  size_t i = n, j = m;
  while (i > 0 && j > 0) {
    if (a[i - 1] == b[j - 1]) { out.push_back(a[i - 1]); --i; --j; }
    else if (best[i - 1][j] >= best[i][j - 1]) --i;
    else --j;
  }
  reverse(out.begin(), out.end());
  return out;
}

// Levenshtein edit distance: fewest insertions, deletions and substitutions.
//
// Only the previous row is ever read, so two rows suffice and the space drops from
// O(n x m) to O(min(n, m)). The traceback is what needs the full table, which is the trade:
// the distance alone is cheap, the alignment is not.
size_t edit_distance(const string& a, const string& b) {
  if (a.size() < b.size()) return edit_distance(b, a);  // keep the short side inner
  vector<size_t> previous(b.size() + 1), current(b.size() + 1);
  for (size_t j = 0; j <= b.size(); ++j) previous[j] = j;  // insert all of b

  for (size_t i = 1; i <= a.size(); ++i) {
    current[0] = i;  // delete all of a so far
    for (size_t j = 1; j <= b.size(); ++j) {
      const size_t substitute = previous[j - 1] + (a[i - 1] == b[j - 1] ? 0 : 1);
      const size_t remove = previous[j] + 1;
      const size_t insert = current[j - 1] + 1;
      current[j] = min({substitute, remove, insert});
    }
    swap(previous, current);
  }
  return previous[b.size()];
}

// 0/1 knapsack: each item taken at most once.
//
// The one-dimensional form iterates weights downwards. Going upwards would let the same
// item be picked twice, because best[room - weight] would already have been updated this
// round - which turns it into the unbounded knapsack. The loop direction is the entire
// difference between the two problems.
long long knapsack(const vector<int>& weights, const vector<int>& values, int capacity) {
  vector<long long> best(capacity + 1, 0);
  for (size_t item = 0; item < weights.size(); ++item)
    for (int room = capacity; room >= weights[item]; --room)
      best[room] = max(best[room], best[room - weights[item]] + values[item]);
  return best[capacity];
}

long long knapsack_unbounded(const vector<int>& weights, const vector<int>& values,
                             int capacity) {
  vector<long long> best(capacity + 1, 0);
  for (size_t item = 0; item < weights.size(); ++item)
    for (int room = weights[item]; room <= capacity; ++room)
      best[room] = max(best[room], best[room - weights[item]] + values[item]);
  return best[capacity];
}

int main() {
  assert(longest_common_subsequence("abcde", "ace") == 3);
  assert(longest_common_subsequence("abc", "def") == 0);
  assert(longest_common_subsequence("", "abc") == 0);
  assert(lcs_string("abcde", "ace") == "ace");
  assert(lcs_string("AGGTAB", "GXTXAYB") == "GTAB");

  assert(edit_distance("kitten", "sitting") == 3);
  assert(edit_distance("", "abc") == 3);
  assert(edit_distance("abc", "") == 3);
  assert(edit_distance("same", "same") == 0);
  // Argument order must not matter: the metric is symmetric.
  assert(edit_distance("flaw", "lawn") == edit_distance("lawn", "flaw"));

  // Weights {1,3,4,5}, values {1,4,5,7}, capacity 7: the best is 4+5 for 9.
  const vector<int> weights = {1, 3, 4, 5};
  const vector<int> values = {1, 4, 5, 7};
  assert(knapsack(weights, values, 7) == 9);
  assert(knapsack(weights, values, 0) == 0);
  assert(knapsack({10}, {100}, 5) == 0);  // nothing fits

  // With unlimited copies the same instance does better, which is the check that the loop
  // direction really is doing the work.
  assert(knapsack({2}, {3}, 6) == 3);
  assert(knapsack_unbounded({2}, {3}, 6) == 9);
  return 0;
}
