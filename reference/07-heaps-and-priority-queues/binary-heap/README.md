# Binary heap

## Idea

A binary min-heap over a flat array. The tree is implicit: the children of i are at 2i+1 and 2i+2, so there are no pointers and the layout is contiguous.

The invariant is local - every parent is no greater than its children - which is weaker than sorting and therefore cheaper to restore. That weaker invariant is exactly enough to know where the minimum is.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check binary_heap.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
