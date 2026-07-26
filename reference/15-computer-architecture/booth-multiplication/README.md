# Booth multiplication

## Idea

Booth's algorithm multiplies two signed numbers, handling the sign with no separate correction step.

A run of ones can be rewritten as a subtraction: 0111 is 8 - 1, so a shift-and-add multiplier that would perform three additions performs one subtraction and one addition instead. Booth detects the edges of those runs by looking at each bit together with the one below it:

00 run of zeros, do nothing 01 end of a run of ones, add the multiplicand 10 start of a run of ones, subtract the multiplicand 11 inside a run of ones, do nothing

The arithmetic right shift is what makes it work on signed values: it preserves the sign bit of the accumulator, so negative partial products stay negative.

The saving is data dependent. On 01010101 it saves nothing; on 01111110 it turns six additions into two operations. Modified Booth, which recodes two bits at a time, is what real hardware uses because it halves the partial products unconditionally.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check booth_multiplication.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
