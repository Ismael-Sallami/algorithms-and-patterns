# Dijkstra over an adjacency matrix of sensor links

## Idea

Sensor nodes relay data to a central server and each link has a transmission time. Dijkstra with the distance table scanned linearly rather than kept in a heap, which is what an adjacency matrix invites: the graph is dense, so scanning n candidates costs no more than maintaining the heap would.

## Cost

O(n²) with the linear scan. A binary heap would give O((V+E) log V), which only pays off on a sparse graph.

## Where it is used

Practical 3 of Algorithmics. An earlier draft of this same file was sitting in the divide-and-conquer repository, which is where it was first written.

## Source

[`src/02-greedy/sensor_network.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/02-greedy/sensor_network.cpp#L90) &mdash; lines 90-146.
