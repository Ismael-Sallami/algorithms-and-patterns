# Depth first search and cycles

## Idea

DFS with an explicit stack rather than recursion, so the depth is bounded by heap memory instead of the call stack. On a graph with a long path the recursive form overflows.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check depth_first_search_and_cycles.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
