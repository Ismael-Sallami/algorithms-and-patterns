// Pattern: KMP and the Z-algorithm
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check kmp_and_z_algorithm.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

// Linear-time pattern matching. The naive scan restarts the pattern after every mismatch,
// which is O(n x m) on inputs like "aaaa...a" against "aaa...b". Both algorithms here
// precompute how much of the pattern can be reused, so no character of the text is
// examined twice.

// KMP failure function: failure[i] is the length of the longest proper prefix of
// pattern[0..i] that is also a suffix of it.
//
// That number is exactly how far the pattern can slide on a mismatch without missing a
// match, because a shorter slide would re-align a prefix already known not to fit. The
// table is built by matching the pattern against itself.
vector<size_t> failure_function(const string& pattern) {
  vector<size_t> failure(pattern.size(), 0);
  size_t length = 0;  // current matched prefix length
  for (size_t i = 1; i < pattern.size(); ++i) {
    while (length > 0 && pattern[i] != pattern[length]) length = failure[length - 1];
    if (pattern[i] == pattern[length]) ++length;
    failure[i] = length;
  }
  return failure;
}

// All occurrences of pattern in text, O(n + m). Overlapping matches are reported, which is
// the correct behaviour and the reason the search continues from the failure value rather
// than resetting.
vector<size_t> kmp_search(const string& text, const string& pattern) {
  vector<size_t> found;
  if (pattern.empty() || pattern.size() > text.size()) return found;
  const vector<size_t> failure = failure_function(pattern);

  size_t matched = 0;
  for (size_t i = 0; i < text.size(); ++i) {
    while (matched > 0 && text[i] != pattern[matched]) matched = failure[matched - 1];
    if (text[i] == pattern[matched]) ++matched;
    if (matched == pattern.size()) {
      found.push_back(i + 1 - pattern.size());
      matched = failure[matched - 1];  // allow the next match to overlap this one
    }
  }
  return found;
}

// The Z-array: z[i] is the length of the longest substring starting at i that is also a
// prefix of the whole string.
//
// It is maintained with a window [left, right] of the rightmost prefix match found so far.
// Inside that window a value can be copied from the already-computed prefix instead of
// recomputed, which is what keeps the total linear.
vector<size_t> z_array(const string& text) {
  const size_t n = text.size();
  vector<size_t> z(n, 0);
  if (n == 0) return z;
  z[0] = n;

  size_t left = 0, right = 0;
  for (size_t i = 1; i < n; ++i) {
    if (i < right) z[i] = min(right - i, z[i - left]);  // reuse the mirrored value
    while (i + z[i] < n && text[z[i]] == text[i + z[i]]) ++z[i];
    if (i + z[i] > right) { left = i; right = i + z[i]; }
  }
  return z;
}

// Pattern matching via the Z-array on pattern + separator + text. The separator must not
// appear in either string, or a match could straddle the join.
vector<size_t> z_search(const string& text, const string& pattern) {
  vector<size_t> found;
  if (pattern.empty()) return found;
  const string combined = pattern + '\x01' + text;
  const vector<size_t> z = z_array(combined);
  for (size_t i = pattern.size() + 1; i < combined.size(); ++i)
    if (z[i] == pattern.size()) found.push_back(i - pattern.size() - 1);
  return found;
}

int main() {
  // Overlapping matches must all be reported.
  assert(kmp_search("ababababa", "aba") == vector<size_t>({0, 2, 4, 6}));
  assert(kmp_search("abcabcabc", "abc") == vector<size_t>({0, 3, 6}));
  assert(kmp_search("hello", "world").empty());
  assert(kmp_search("aaa", "aaaa").empty());  // pattern longer than the text
  assert(kmp_search("abc", "").empty());
  assert(kmp_search("aaaa", "aa") == vector<size_t>({0, 1, 2}));

  assert(failure_function("ababaca") == vector<size_t>({0, 0, 1, 2, 3, 0, 1}));
  assert(failure_function("aaaa") == vector<size_t>({0, 1, 2, 3}));
  assert(failure_function("abcd") == vector<size_t>({0, 0, 0, 0}));

  const vector<size_t> z = z_array("aabxaayaab");
  assert(z[0] == 10);  // the whole length, by definition
  assert(z[1] == 1);
  assert(z[4] == 2);
  assert(z[7] == 3);

  // Two independent algorithms must agree on every input, which is the real test.
  for (const string& text : {"ababababa", "aaaa", "abcabcabc", "xyz", ""})
    for (const string& pattern : {"a", "aa", "aba", "abc", "z"})
      assert(kmp_search(text, pattern) == z_search(text, pattern));
  return 0;
}
