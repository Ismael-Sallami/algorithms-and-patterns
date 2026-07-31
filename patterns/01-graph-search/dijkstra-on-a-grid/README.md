# Dijkstra over a weighted grid with composite state

## Idea

Uniform-cost search with a min-heap keyed on accumulated cost. Terrain type and height change both feed the edge weight, so the cheapest route is not the shortest one. The distance table is four-dimensional - row, column, orientation, and whether the agent carries the boots that make some terrain cheap - because the same cell reached in a different condition is a different node and must keep its own best-known cost.

## Cost

O((V + E) log V) with a binary heap. V = rows x cols x 8 x 2; the extra factor of 2 is the boots flag.

## Where it is used

Level 2 of the rescuer agent, where terrain cost is known and the goal is the cheapest path rather than the shortest.

## Source

[`rescue-agents/src/rescatador.cpp`](https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/rescatador.cpp#L1444-L1524) &mdash; lines 1444-1524.
