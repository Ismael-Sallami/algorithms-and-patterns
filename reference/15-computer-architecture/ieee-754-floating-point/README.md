# IEEE-754 floating point

## Idea

IEEE-754 single precision, taken apart by hand.

| sign (1) | exponent (8) | mantissa (23) |

The value is (-1)^sign x 1.mantissa x 2^(exponent - 127) for normal numbers. Two design choices explain most floating-point surprises:

The leading 1 is implicit. Not storing it buys an extra bit of precision but means exponent 0 needs a special reading - subnormals, where the implicit bit is 0 instead, so values decay smoothly to zero rather than jumping.

The exponent is biased by 127 rather than stored in two's complement, which makes the bit pattern of a positive float compare correctly as an integer.

Exponent 255 is reserved: mantissa zero is infinity, anything else is NaN. That is why there are millions of distinct NaN patterns, and why NaN != NaN - the comparison is defined to be false, not the bits.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check ieee_754_floating_point.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
