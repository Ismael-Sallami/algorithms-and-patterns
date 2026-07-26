# Floyd-Warshall

## Idea

Shortest paths between every pair of vertices.

Three nested loops, and the order of them is the algorithm. The outer loop is the intermediate vertex k, and the invariant after iteration k is: distance[i][j] is the shortest path from i to j using only vertices 0..k in between. Growing the permitted set one vertex at a time is why this is dynamic programming and not just a triple loop - putting k innermost gives a wrong answer.

O(V^3) time, O(V^2) space. Running Dijkstra from every vertex is O(V x E log V), which is better on sparse graphs; Floyd-Warshall wins on dense ones, handles negative edges, and is about ten lines.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check floyd_warshall.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
