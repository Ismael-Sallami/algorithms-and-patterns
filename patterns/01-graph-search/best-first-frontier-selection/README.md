# Best-first selection of the next cell to explore

## Idea

Exploration target selection, separate from path planning. Every candidate frontier cell is scored by how much unknown map surrounds it and how far away it is, then pushed into a max-heap. The agent pops the best candidate and only then runs a shortest-path search towards it. Splitting 'where to go' from 'how to get there' keeps both parts simple.

## Cost

O(n log n) to build the queue over n candidate cells, O(log n) per pop.

## Where it is used

The discovery phase of the rescuer agent, which has to reveal the map before it can plan over it.

## Source

[`rescue-agents/src/rescatador.cpp`](https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/rescatador.cpp#L1650-L1673) &mdash; lines 1650-1673.
