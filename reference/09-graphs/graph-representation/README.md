# Graph representation

## Idea

The representation decides which operations are cheap, so it is the first design choice in any graph problem rather than an implementation detail.

adjacency list        adjacency matrix space          O(V + E)              O(V^2) has edge?      O(deg(u))             O(1) neighbours     O(deg(u))             O(V)

Real graphs are sparse - E closer to V than to V^2 - so the list wins on space and on iteration, which is what traversals do. The matrix is worth it only for dense graphs, or when edge existence is queried far more often than neighbours are enumerated.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check graph_representation.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
