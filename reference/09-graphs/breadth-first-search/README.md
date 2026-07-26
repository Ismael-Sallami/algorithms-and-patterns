# Breadth first search

## Idea

BFS on an unweighted graph gives shortest paths in edges, because it settles vertices in non-decreasing distance order. That is the one thing DFS cannot do.

Marking on enqueue rather than on dequeue matters: without it a vertex reachable from several frontier vertices enters the queue several times, and the queue can grow to O(E).

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check breadth_first_search.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
