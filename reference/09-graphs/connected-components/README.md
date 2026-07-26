# Connected components

## Idea

Labels every vertex with its component index. One traversal per unlabelled vertex, and each vertex is traversed once overall, so the total is O(V + E) no matter how many components there are.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check connected_components.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
