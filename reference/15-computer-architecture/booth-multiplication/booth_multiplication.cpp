// Pattern: Booth multiplication
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check booth_multiplication.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <cstdint>

using namespace std;

// Booth's algorithm multiplies two signed numbers, handling the sign with no separate
// correction step.
//
// A run of ones can be rewritten as a subtraction: 0111 is 8 - 1, so a shift-and-add
// multiplier that would perform three additions performs one subtraction and one
// addition instead. Booth detects the edges of those runs by looking at each bit
// together with the one below it:
//
//   00 run of zeros, do nothing
//   01 end of a run of ones, add the multiplicand
//   10 start of a run of ones, subtract the multiplicand
//   11 inside a run of ones, do nothing
//
// The arithmetic right shift is what makes it work on signed values: it preserves the
// sign bit of the accumulator, so negative partial products stay negative.
//
// The saving is data dependent. On 01010101 it saves nothing; on 01111110 it turns six
// additions into two operations. Modified Booth, which recodes two bits at a time, is
// what real hardware uses because it halves the partial products unconditionally.
int64_t booth_multiply(int32_t multiplicand, int32_t multiplier, int bits = 32) {
  const int64_t mask = (bits == 64) ? ~int64_t(0) : ((int64_t(1) << bits) - 1);
  int64_t accumulator = 0;  // upper half of the product
  // The lower half is an unsigned n-bit register, so the multiplier has to be
  // truncated to n bits. Assigning a negative value straight in leaves the sign
  // extension above bit n-1, and the shifts then feed those bits back as data.
  int64_t quotient = static_cast<int64_t>(static_cast<uint64_t>(multiplier) & static_cast<uint64_t>(mask));
  int previous_bit = 0;  // the bit shifted out last round
  const int64_t m = multiplicand;

  for (int step = 0; step < bits; ++step) {
    const int current_bit = static_cast<int>(quotient & 1);
    if (current_bit == 0 && previous_bit == 1) accumulator += m;       // 01
    else if (current_bit == 1 && previous_bit == 0) accumulator -= m;  // 10

    // Arithmetic shift of the combined (accumulator, quotient) register right by one.
    // The low bit of the accumulator becomes the high bit of the quotient.
    previous_bit = current_bit;
    const int64_t carry = accumulator & 1;
    accumulator >>= 1;  // signed type: the shift is arithmetic, sign preserved
    quotient = ((quotient >> 1) | (carry << (bits - 1))) & mask;
  }
  return (accumulator << bits) | quotient;
}

// Plain shift-and-add, for contrast. Unsigned only: on a negative multiplier it treats
// the sign bit as a value of 2^(n-1) and gets the answer wrong, which is the problem
// Booth exists to solve.
uint64_t shift_and_add(uint32_t a, uint32_t b) {
  uint64_t product = 0;
  uint64_t shifted = a;
  while (b != 0) {
    if (b & 1) product += shifted;
    shifted <<= 1;
    b >>= 1;
  }
  return product;
}

int main() {
  assert(booth_multiply(7, 3) == 21);
  assert(booth_multiply(-7, 3) == -21);
  assert(booth_multiply(7, -3) == -21);
  assert(booth_multiply(-7, -3) == 21);
  assert(booth_multiply(0, 12345) == 0);
  assert(booth_multiply(1, -1) == -1);

  // A long run of ones, the case the recoding is for.
  assert(booth_multiply(126, 5) == 630);
  assert(booth_multiply(-126, 5) == -630);

  // Wider values, where a 32-bit product would overflow.
  assert(booth_multiply(100000, 100000) == 10000000000LL);
  assert(booth_multiply(-100000, 100000) == -10000000000LL);

  // Exhaustive at a small width, which is where an off-by-one in the shift shows.
  for (int a = -8; a <= 7; ++a)
    for (int b = -8; b <= 7; ++b)
      assert(booth_multiply(a, b, 8) == static_cast<int64_t>(a) * b);

  assert(shift_and_add(7, 3) == 21);
  assert(shift_and_add(255, 255) == 65025);
  return 0;
}
