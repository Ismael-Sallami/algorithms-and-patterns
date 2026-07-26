# Bellman-Ford

## Idea

Bellman-Ford: shortest paths with negative weights allowed.

Dijkstra's argument fails once an edge can be negative, because a longer route may still improve later. Bellman-Ford gives that up and relaxes every edge V-1 times. That is enough because a shortest path visits at most V vertices, so it has at most V-1 edges, and pass i settles every path of i edges.

The cost is O(V x E) against Dijkstra's O(E log V). What it buys is negative weights and, more usefully, detection of negative cycles: if a V-th pass still improves something, no shortest path exists at all.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check bellman_ford.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
