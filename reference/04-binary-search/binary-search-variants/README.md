# Binary search variants

## Idea

Binary search comes down to maintaining one invariant and never breaking it. The two bounds below are written as half-open [low, high) searches: the loop ends when the range is empty and `low` is the answer, so there is no separate found/not-found branch and no off-by-one at the edges.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check binary_search_variants.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
