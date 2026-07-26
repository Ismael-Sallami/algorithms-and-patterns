// Pattern: Rolling hash and palindromes
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check rolling_hash_and_palindromes.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <string>
#include <vector>

using namespace std;

// Rabin-Karp: pattern matching by hashing.
//
// A rolling hash updates in O(1) as the window slides - remove the leaving character's
// contribution, shift, add the entering one - so all n window hashes cost O(n) rather than
// O(n x m). A hash match is only evidence, not proof, so it is verified by comparison;
// with a large prime modulus collisions are rare enough that the expected cost stays O(n).
//
// Against KMP, this loses the worst-case guarantee and gains the ability to compare
// arbitrary substrings in O(1) once the prefix hashes are built.
class RollingHash {
  static constexpr uint64_t kBase = 257;
  static constexpr uint64_t kModulus = 1000000007ULL;
  vector<uint64_t> prefix;  // prefix[i] = hash of the first i characters
  vector<uint64_t> power;

 public:
  explicit RollingHash(const string& text)
      : prefix(text.size() + 1, 0), power(text.size() + 1, 1) {
    for (size_t i = 0; i < text.size(); ++i) {
      prefix[i + 1] = (prefix[i] * kBase + static_cast<unsigned char>(text[i])) % kModulus;
      power[i + 1] = (power[i] * kBase) % kModulus;
    }
  }

  // Hash of text[from, to). The subtraction is what makes any substring O(1).
  uint64_t of(size_t from, size_t to) const {
    const uint64_t high = prefix[to];
    const uint64_t low = (prefix[from] * power[to - from]) % kModulus;
    return (high + kModulus - low) % kModulus;
  }
};

vector<size_t> rabin_karp(const string& text, const string& pattern) {
  vector<size_t> found;
  if (pattern.empty() || pattern.size() > text.size()) return found;
  const RollingHash text_hash(text);
  const RollingHash pattern_hash(pattern);
  const uint64_t target = pattern_hash.of(0, pattern.size());

  for (size_t i = 0; i + pattern.size() <= text.size(); ++i) {
    if (text_hash.of(i, i + pattern.size()) != target) continue;
    // A hash match is evidence, not proof. Verify before reporting.
    if (text.compare(i, pattern.size(), pattern) == 0) found.push_back(i);
  }
  return found;
}

// Manacher: longest palindromic substring in O(n).
//
// Expanding around every centre is O(n^2). Manacher reuses the fact that a palindrome is
// symmetric: inside an already-known palindrome, the radius at a position can be seeded
// from its mirror rather than recomputed. Transforming the string with separators between
// every character removes the even-length special case, so there is one loop instead of
// two.
string longest_palindrome(const string& text) {
  if (text.empty()) return "";
  string padded = "|";
  for (char c : text) {
    padded.push_back(c);
    padded.push_back('|');
  }

  const size_t n = padded.size();
  vector<size_t> radius(n, 0);
  size_t centre = 0, right = 0;

  for (size_t i = 0; i < n; ++i) {
    if (i < right) {
      const size_t mirror = 2 * centre - i;
      radius[i] = min(right - i, radius[mirror]);  // seed from the mirror
    }
    while (i >= radius[i] + 1 && i + radius[i] + 1 < n &&
           padded[i - radius[i] - 1] == padded[i + radius[i] + 1])
      ++radius[i];
    if (i + radius[i] > right) { centre = i; right = i + radius[i]; }
  }

  size_t best_centre = 0, best_radius = 0;
  for (size_t i = 0; i < n; ++i)
    if (radius[i] > best_radius) { best_radius = radius[i]; best_centre = i; }

  // Map back out of the padded coordinates.
  const size_t start = (best_centre - best_radius) / 2;
  return text.substr(start, best_radius);
}

int main() {
  assert(rabin_karp("ababababa", "aba") == vector<size_t>({0, 2, 4, 6}));
  assert(rabin_karp("abcabcabc", "abc") == vector<size_t>({0, 3, 6}));
  assert(rabin_karp("hello", "world").empty());
  assert(rabin_karp("aaaa", "aa") == vector<size_t>({0, 1, 2}));
  assert(rabin_karp("abc", "").empty());

  // O(1) substring comparison, the thing a plain scan cannot do.
  const RollingHash hash("abcabc");
  assert(hash.of(0, 3) == hash.of(3, 6));
  assert(hash.of(0, 2) != hash.of(1, 3));

  assert(longest_palindrome("babad").size() == 3);  // "bab" or "aba"
  assert(longest_palindrome("cbbd") == "bb");       // even length
  assert(longest_palindrome("a") == "a");
  assert(longest_palindrome("") == "");
  assert(longest_palindrome("racecar") == "racecar");
  assert(longest_palindrome("abcde").size() == 1);  // no palindrome longer than one
  assert(longest_palindrome("aaaa") == "aaaa");
  return 0;
}
