// Pattern: Two's complement arithmetic
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check twos_complement.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <string>

using namespace std;

// Two's complement is why one adder circuit serves both signed and unsigned
// arithmetic: negation is "invert the bits and add one", so subtraction is addition of
// a negated operand and no separate subtractor is needed.
//
// It also explains the asymmetric range. In n bits the values run from -2^(n-1) to
// 2^(n-1) - 1: one more negative than positive, because zero occupies a slot in the
// non-negative half. That is why negating the most negative value overflows and
// returns itself.
uint32_t to_twos_complement(int32_t value, int bits) {
  const uint32_t mask = (bits == 32) ? 0xFFFFFFFFu : ((1u << bits) - 1);
  return static_cast<uint32_t>(value) & mask;
}

// Sign extension is the whole of decoding: if the top bit of the field is set, every
// bit above it must be set too, or the value reads as a large positive number.
int32_t from_twos_complement(uint32_t pattern, int bits) {
  const uint32_t sign_bit = 1u << (bits - 1);
  const uint32_t mask = (bits == 32) ? 0xFFFFFFFFu : ((1u << bits) - 1);
  pattern &= mask;
  if (pattern & sign_bit) return static_cast<int32_t>(pattern | ~mask);
  return static_cast<int32_t>(pattern);
}

// What a load-byte or load-halfword instruction does. Getting it wrong is how a -1
// byte becomes 255.
int32_t sign_extend(uint32_t value, int from_bits) {
  return from_twos_complement(value, from_bits);
}

// Signed addition overflows when the operands share a sign and the result does not.
// Hardware detects it by comparing the carry into the sign bit with the carry out.
bool addition_overflows(int32_t a, int32_t b, int bits) {
  const int64_t sum = static_cast<int64_t>(a) + b;
  const int64_t low = -(int64_t(1) << (bits - 1));
  const int64_t high = (int64_t(1) << (bits - 1)) - 1;
  return sum < low || sum > high;
}

string to_binary(uint32_t value, int bits) {
  string out;
  for (int i = bits - 1; i >= 0; --i) out.push_back(((value >> i) & 1u) ? '1' : '0');
  return out;
}

int main() {
  assert(to_binary(to_twos_complement(5, 8), 8) == "00000101");
  assert(to_binary(to_twos_complement(-5, 8), 8) == "11111011");   // invert 5, add 1
  assert(to_binary(to_twos_complement(-1, 8), 8) == "11111111");
  assert(to_binary(to_twos_complement(-128, 8), 8) == "10000000"); // most negative

  for (int value = -128; value <= 127; ++value)
    assert(from_twos_complement(to_twos_complement(value, 8), 8) == value);

  // 0xFF as a byte is -1, not 255.
  assert(sign_extend(0xFF, 8) == -1);
  assert(sign_extend(0x7F, 8) == 127);
  assert(sign_extend(0x80, 8) == -128);
  assert(sign_extend(0xFFFF, 16) == -1);

  // The asymmetric range: negating the most negative value overflows to itself.
  assert(from_twos_complement(to_twos_complement(-(-128), 8), 8) == -128);

  assert(!addition_overflows(100, 27, 8));   // 127 fits
  assert(addition_overflows(100, 28, 8));    // 128 does not
  assert(addition_overflows(-100, -29, 8));  // -129 does not
  assert(!addition_overflows(-100, -28, 8)); // -128 fits
  // Opposite signs can never overflow: the magnitude only shrinks.
  assert(!addition_overflows(127, -128, 8));
  return 0;
}
