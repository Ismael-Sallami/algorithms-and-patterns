# Fenwick tree

## Idea

A Fenwick tree (binary indexed tree) does prefix sums with point updates in O(log n), like a segment tree, in half the space and a fraction of the code.

It works because every index covers a range whose length is its lowest set bit. Stripping that bit walks down the prefix decomposition; adding it walks up the indices a position contributes to. The whole structure is those two operations. The trade against a segment tree is that it only handles invertible operations - sums, not minima.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check fenwick_tree.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
