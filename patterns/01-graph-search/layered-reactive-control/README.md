# Layered reactive control without a plan

## Idea

The behaviour used when the map is still unknown and no search is possible: a priority-ordered rule set over the current sensor reading. Rules are tried in order and the first that applies wins, so adding a rule cannot silently disable an earlier one. This is the layer the planners replace once there is enough map to plan over.

## Cost

O(r) per decision for r rules, with no memory beyond the visit counters. Constant time and constant space per tick.

## Where it is used

Level 0 of the rescuer agent, and the fallback whenever planning fails.

## Source

[`rescue-agents/src/rescatador.cpp`](https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/rescatador.cpp#L121-L343) &mdash; lines 121-343.
