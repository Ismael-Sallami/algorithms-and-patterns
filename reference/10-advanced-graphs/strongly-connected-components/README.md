# Strongly connected components

## Idea

Strongly connected components: maximal sets where every vertex reaches every other. Contracting each one turns any directed graph into a DAG, which is what makes topological reasoning available on cyclic graphs.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check strongly_connected_components.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
