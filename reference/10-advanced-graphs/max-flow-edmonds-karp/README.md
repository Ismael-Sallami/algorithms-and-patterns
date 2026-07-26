# Maximum flow by Edmonds-Karp

## Idea

Maximum flow from source to sink.

The Ford-Fulkerson idea is to repeatedly push flow along any path with spare capacity. What makes it correct is the residual graph: sending f units along an edge also creates a reverse edge of capacity f, so a later augmenting path can undo an earlier bad choice. Without those back edges a greedy first path can block the optimum permanently.

Edmonds-Karp is Ford-Fulkerson with BFS, so each augmenting path is the shortest available. That choice bounds the number of augmentations at O(V x E) regardless of the capacities, giving O(V x E^2) overall. With DFS instead, the running time depends on the capacity values.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check max_flow_edmonds_karp.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
