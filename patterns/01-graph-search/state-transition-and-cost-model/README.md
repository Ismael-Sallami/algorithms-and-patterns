# State transition function and edge cost model

## Idea

The part every search above depends on: given a state and an action, produce the successor state; given a terrain type and a height change, produce the edge weight. Keeping the transition and the cost outside the search loop means one implementation is shared by BFS, Dijkstra and A*, and changing the cost model does not touch the search code.

## Cost

O(1) per call. Both functions are table lookups plus bounds checks.

## Where it is used

Shared by every planner in the rescuer agent.

## Source

[`rescue-agents/src/rescatador.cpp`](https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/rescatador.cpp#L1164) &mdash; lines 1164-1220, 1347-1402, 1404-1442.
