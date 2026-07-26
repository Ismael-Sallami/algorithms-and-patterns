// Pattern: Cache blocking
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check cache_blocking.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>

using namespace std;

// Loop tiling, and why memory layout beats operation count.
//
// All three matrix multiplications below perform exactly the same 2n^3 arithmetic
// operations. They differ only in the order they touch memory, and that difference is
// worth a large constant factor on any machine with a cache.
//
// A C++ matrix is row-major, so walking a row is sequential and walking a column
// strides by the row length. In the naive i-j-k loop the inner loop walks a column of
// B: every access is a new cache line, and for a matrix wider than the cache every one
// is a miss.
//
// Two fixes:
//
//   Loop interchange to i-k-j makes the inner loop walk rows of both B and C. Same
//   arithmetic, sequential access, large speed-up for a one-line change.
//
//   Tiling splits the iteration space into blocks small enough that a block of each
//   operand fits in cache at once. Each loaded element is then reused across the whole
//   block before eviction, which raises arithmetic intensity - operations per byte
//   loaded - rather than merely reducing stride.
using Matrix = vector<vector<double>>;

Matrix multiply_naive(const Matrix& a, const Matrix& b) {
  const size_t n = a.size();
  Matrix c(n, vector<double>(n, 0.0));
  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < n; ++j) {
      double sum = 0.0;
      for (size_t k = 0; k < n; ++k) sum += a[i][k] * b[k][j];  // b strides by a row
      c[i][j] = sum;
    }
  return c;
}

Matrix multiply_interchanged(const Matrix& a, const Matrix& b) {
  const size_t n = a.size();
  Matrix c(n, vector<double>(n, 0.0));
  for (size_t i = 0; i < n; ++i)
    for (size_t k = 0; k < n; ++k) {
      const double scale = a[i][k];
      // Both b and c are now walked along a row.
      for (size_t j = 0; j < n; ++j) c[i][j] += scale * b[k][j];
    }
  return c;
}

Matrix multiply_tiled(const Matrix& a, const Matrix& b, size_t tile) {
  const size_t n = a.size();
  Matrix c(n, vector<double>(n, 0.0));
  for (size_t i0 = 0; i0 < n; i0 += tile)
    for (size_t k0 = 0; k0 < n; k0 += tile)
      for (size_t j0 = 0; j0 < n; j0 += tile) {
        const size_t i_end = min(i0 + tile, n);
        const size_t k_end = min(k0 + tile, n);
        const size_t j_end = min(j0 + tile, n);
        for (size_t i = i0; i < i_end; ++i)
          for (size_t k = k0; k < k_end; ++k) {
            const double scale = a[i][k];
            for (size_t j = j0; j < j_end; ++j) c[i][j] += scale * b[k][j];
          }
      }
  return c;
}

// Transposing before multiplying is the other standard fix: it makes the column walk
// sequential at the cost of one O(n^2) pass, which is cheap against O(n^3).
Matrix transpose(const Matrix& m) {
  const size_t n = m.size();
  Matrix t(n, vector<double>(n, 0.0));
  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < n; ++j) t[j][i] = m[i][j];
  return t;
}

static bool nearly_equal(const Matrix& x, const Matrix& y) {
  if (x.size() != y.size()) return false;
  for (size_t i = 0; i < x.size(); ++i)
    for (size_t j = 0; j < x[i].size(); ++j)
      if (fabs(x[i][j] - y[i][j]) > 1e-9) return false;
  return true;
}

int main() {
  const size_t n = 64;
  Matrix a(n, vector<double>(n)), b(n, vector<double>(n));
  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < n; ++j) {
      a[i][j] = static_cast<double>((i * 7 + j * 3) % 10);
      b[i][j] = static_cast<double>((i * 5 + j * 11) % 10);
    }

  // Correctness first: all three orderings must agree. A tiling bug shows up as a
  // wrong result, not as a slow one.
  const Matrix reference = multiply_naive(a, b);
  assert(nearly_equal(multiply_interchanged(a, b), reference));
  assert(nearly_equal(multiply_tiled(a, b, 8), reference));
  assert(nearly_equal(multiply_tiled(a, b, 16), reference));
  // A tile as wide as the matrix degenerates to the untiled loop; a tile of one is the
  // worst case. Both must still be correct.
  assert(nearly_equal(multiply_tiled(a, b, n), reference));
  assert(nearly_equal(multiply_tiled(a, b, 1), reference));

  // Transposing twice is the identity, which is the check that it is right.
  assert(nearly_equal(transpose(transpose(a)), a));

  Matrix identity(n, vector<double>(n, 0.0));
  for (size_t i = 0; i < n; ++i) identity[i][i] = 1.0;
  assert(nearly_equal(multiply_tiled(a, identity, 8), a));
  return 0;
}
