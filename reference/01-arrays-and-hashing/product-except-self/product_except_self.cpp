// Pattern: Product except self
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check product_except_self.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

// Product of every element except the current one, without division.
//
// Division would be one pass and breaks on any zero in the input. Instead: one
// left-to-right pass accumulating the product of everything before each position,
// then one right-to-left pass multiplying in everything after. The output array
// carries the left products, so the extra space is O(1).
vector<long long> product_except_self(const vector<int>& values) {
  const size_t n = values.size();
  vector<long long> result(n, 1);

  long long running = 1;
  for (size_t i = 0; i < n; ++i) {
    result[i] = running;
    running *= values[i];
  }
  running = 1;
  for (size_t i = n; i-- > 0;) {
    result[i] *= running;
    running *= values[i];
  }
  return result;
}

int main() {
  assert(product_except_self({1, 2, 3, 4}) == vector<long long>({24, 12, 8, 6}));
  // One zero: every other position becomes zero, the zero's position does not.
  assert(product_except_self({0, 4, 5}) == vector<long long>({20, 0, 0}));
  // Two zeros: all zero. Division would have divided by zero here.
  assert(product_except_self({0, 0, 3}) == vector<long long>({0, 0, 0}));
  assert(product_except_self({2}) == vector<long long>({1}));
  assert(product_except_self({-1, 2, -3}) == vector<long long>({-6, 3, -2}));
  return 0;
}
