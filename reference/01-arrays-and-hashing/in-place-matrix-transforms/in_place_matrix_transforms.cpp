// Pattern: In place matrix transforms
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check in_place_matrix_transforms.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

using Matrix = vector<vector<int>>;

// Rotating a square matrix 90 degrees clockwise with no second matrix.
//
// Transpose, then reverse each row. Transposing reflects across the main diagonal,
// reversing reflects across the vertical axis, and two reflections compose into a
// rotation. Two simple passes avoid the index arithmetic of a four-way cycle swap.
void rotate_clockwise(Matrix& matrix) {
  const size_t n = matrix.size();
  for (size_t row = 0; row < n; ++row)
    for (size_t col = row + 1; col < n; ++col) swap(matrix[row][col], matrix[col][row]);
  for (auto& row : matrix) reverse(row.begin(), row.end());
}

// Reads a rectangular matrix in spiral order. Four moving bounds rather than a
// visited matrix, so the space stays O(1). The two inner guards matter: without them
// a single remaining row or column is emitted twice.
vector<int> spiral_order(const Matrix& matrix) {
  vector<int> out;
  if (matrix.empty()) return out;
  int top = 0, bottom = static_cast<int>(matrix.size()) - 1;
  int left = 0, right = static_cast<int>(matrix[0].size()) - 1;

  while (top <= bottom && left <= right) {
    for (int col = left; col <= right; ++col) out.push_back(matrix[top][col]);
    ++top;
    for (int row = top; row <= bottom; ++row) out.push_back(matrix[row][right]);
    --right;
    if (top <= bottom) {
      for (int col = right; col >= left; --col) out.push_back(matrix[bottom][col]);
      --bottom;
    }
    if (left <= right) {
      for (int row = bottom; row >= top; --row) out.push_back(matrix[row][left]);
      ++left;
    }
  }
  return out;
}

int main() {
  Matrix m = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  rotate_clockwise(m);
  assert(m == Matrix({{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}));

  assert(spiral_order({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}) ==
         vector<int>({1, 2, 3, 6, 9, 8, 7, 4, 5}));
  // Single row and single column: the guards are what stop double emission.
  assert(spiral_order({{1, 2, 3}}) == vector<int>({1, 2, 3}));
  assert(spiral_order({{1}, {2}, {3}}) == vector<int>({1, 2, 3}));
  return 0;
}
