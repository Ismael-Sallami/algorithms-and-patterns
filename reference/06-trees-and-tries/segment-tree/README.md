# Segment tree

## Idea

Range queries with point updates. A prefix-sum array gives O(1) queries and O(n) updates; a plain scan gives O(1) updates and O(n) queries. A segment tree makes both O(log n), which is the right trade when updates and queries are interleaved.

Written iteratively over a 1-indexed array of size 2n: leaves live at [n, 2n) and a node's parent is at i/2. No recursion and no child pointers.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check segment_tree.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
