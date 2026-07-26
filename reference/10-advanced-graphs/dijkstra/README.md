# Dijkstra's algorithm

## Idea

Dijkstra over an adjacency list with a binary heap.

The correctness argument: when a vertex is popped, no shorter route to it can still be found, because any such route would pass through an unpopped vertex whose distance is already at least as large. That argument needs non-negative weights, which is the algorithm's one hard requirement.

This is the lazy variant: instead of decreasing a key in place, a better distance is pushed as a new entry and stale entries are skipped on pop. The heap can hold up to E entries rather than V, but it needs no indexed heap and the bound stays O(E log V).

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check dijkstra.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
