# KMP and the Z-algorithm

## Idea

Linear-time pattern matching. The naive scan restarts the pattern after every mismatch, which is O(n x m) on inputs like "aaaa...a" against "aaa...b". Both algorithms here precompute how much of the pattern can be reused, so no character of the text is examined twice.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check kmp_and_z_algorithm.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
