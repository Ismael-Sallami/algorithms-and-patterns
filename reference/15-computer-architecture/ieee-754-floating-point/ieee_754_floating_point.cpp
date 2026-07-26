// Pattern: IEEE-754 floating point
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check ieee_754_floating_point.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstring>

using namespace std;

// IEEE-754 single precision, taken apart by hand.
//
//   | sign (1) | exponent (8) | mantissa (23) |
//
// The value is (-1)^sign x 1.mantissa x 2^(exponent - 127) for normal numbers. Two
// design choices explain most floating-point surprises:
//
//   The leading 1 is implicit. Not storing it buys an extra bit of precision but means
//   exponent 0 needs a special reading - subnormals, where the implicit bit is 0
//   instead, so values decay smoothly to zero rather than jumping.
//
//   The exponent is biased by 127 rather than stored in two's complement, which makes
//   the bit pattern of a positive float compare correctly as an integer.
//
// Exponent 255 is reserved: mantissa zero is infinity, anything else is NaN. That is
// why there are millions of distinct NaN patterns, and why NaN != NaN - the comparison
// is defined to be false, not the bits.
struct Parts {
  uint32_t sign;
  uint32_t exponent;  // raw, still biased
  uint32_t mantissa;  // raw, implicit bit not included
};

Parts decompose(float value) {
  uint32_t bits;
  memcpy(&bits, &value, sizeof bits);  // the portable reinterpretation
  return {bits >> 31, (bits >> 23) & 0xFF, bits & 0x7FFFFF};
}

float compose(Parts parts) {
  const uint32_t bits = (parts.sign << 31) | (parts.exponent << 23) | parts.mantissa;
  float value;
  memcpy(&value, &bits, sizeof value);
  return value;
}

bool is_normal(Parts p) { return p.exponent != 0 && p.exponent != 0xFF; }
bool is_subnormal(Parts p) { return p.exponent == 0 && p.mantissa != 0; }
bool is_infinity(Parts p) { return p.exponent == 0xFF && p.mantissa == 0; }
bool is_nan(Parts p) { return p.exponent == 0xFF && p.mantissa != 0; }
int unbiased_exponent(Parts p) { return static_cast<int>(p.exponent) - 127; }

// The gap between consecutive representable floats near a value. Precision is
// relative, not absolute: the gap doubles with every exponent step, which is why
// adding 1 to a large float can change nothing.
float spacing_at(float value) {
  Parts parts = decompose(value);
  parts.mantissa += 1;
  return compose(parts) - value;
}

int main() {
  Parts one = decompose(1.0f);
  assert(one.sign == 0 && one.exponent == 127 && one.mantissa == 0);
  assert(unbiased_exponent(one) == 0 && is_normal(one));

  Parts minus_two = decompose(-2.0f);
  assert(minus_two.sign == 1 && unbiased_exponent(minus_two) == 1);

  for (float value : {1.0f, -1.0f, 0.5f, 3.14159f, 1e10f, -1e-10f})
    assert(compose(decompose(value)) == value);

  // Zero and negative zero: different bits, equal by comparison.
  assert(decompose(-0.0f).sign == 1);
  assert(0.0f == -0.0f);

  assert(is_infinity(decompose(INFINITY)));
  assert(is_nan(decompose(NAN)));
  const float nan_value = NAN;
  assert(!(nan_value == nan_value));  // a rule of the standard, not of the bits

  // A subnormal: the implicit bit is 0, so precision degrades without jumping to zero.
  const float tiny = compose({0, 0, 1});
  assert(is_subnormal(decompose(tiny)) && tiny > 0.0f);

  // Precision is relative. The gap at 1.0 is 2^-23; at 2^24 it is 2 whole units,
  // which is why the addition below is lost entirely.
  assert(spacing_at(1.0f) == powf(2.0f, -23.0f));
  const float big = powf(2.0f, 24.0f);
  assert(big + 1.0f == big);
  assert(spacing_at(big) == 2.0f);

  // 0.1 is not representable in binary, so the sum drifts.
  float accumulated = 0.0f;
  for (int i = 0; i < 10; ++i) accumulated += 0.1f;
  assert(accumulated != 1.0f);
  assert(fabsf(accumulated - 1.0f) < 1e-6f);
  return 0;
}
