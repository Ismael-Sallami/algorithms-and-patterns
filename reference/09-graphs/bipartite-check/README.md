# Bipartite check

## Idea

A graph is bipartite when its vertices split into two sets with no edge inside either. Equivalently it is two-colourable, and equivalently it has no odd cycle - which is what the traversal actually detects.

BFS assigns the opposite colour to each neighbour. A conflict means an edge between same-coloured vertices, which closes a cycle of odd length. The outer loop matters: a disconnected graph is bipartite only if every component is.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check bipartite_check.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
