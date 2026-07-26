# Cache blocking

## Idea

Loop tiling, and why memory layout beats operation count.

All three matrix multiplications below perform exactly the same 2n^3 arithmetic operations. They differ only in the order they touch memory, and that difference is worth a large constant factor on any machine with a cache.

A C++ matrix is row-major, so walking a row is sequential and walking a column strides by the row length. In the naive i-j-k loop the inner loop walks a column of B: every access is a new cache line, and for a matrix wider than the cache every one is a miss.

Two fixes:

Loop interchange to i-k-j makes the inner loop walk rows of both B and C. Same arithmetic, sequential access, large speed-up for a one-line change.

Tiling splits the iteration space into blocks small enough that a block of each operand fits in cache at once. Each loaded element is then reused across the whole block before eviction, which raises arithmetic intensity - operations per byte loaded - rather than merely reducing stride.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check cache_blocking.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
