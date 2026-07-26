# Minimum spanning tree

## Idea

Two ways to build a minimum spanning tree. Both are greedy and both are correct for the same reason - the cut property: the lightest edge crossing any partition of the vertices belongs to some MST. They differ in which cut they look at, and that decides which representation suits them.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check minimum_spanning_tree.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
