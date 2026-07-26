# Two's complement arithmetic

## Idea

Two's complement is why one adder circuit serves both signed and unsigned arithmetic: negation is "invert the bits and add one", so subtraction is addition of a negated operand and no separate subtractor is needed.

It also explains the asymmetric range. In n bits the values run from -2^(n-1) to 2^(n-1) - 1: one more negative than positive, because zero occupies a slot in the non-negative half. That is why negating the most negative value overflows and returns itself.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check twos_complement.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
