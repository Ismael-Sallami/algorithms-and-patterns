# Union find

## Idea

Disjoint set union. Two optimisations that only work together:

union by size keeps the trees shallow by hanging the smaller under the larger path compression flattens a path to the root every time it is walked

With both, the amortised cost per operation is the inverse Ackermann function, which is below 5 for any input that fits in memory. With neither, a chain of unions builds a list and each find is O(n).

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check union_find.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
