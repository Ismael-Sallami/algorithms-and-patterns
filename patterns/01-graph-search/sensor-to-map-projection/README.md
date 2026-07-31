# Projecting a local sensor reading onto a global map

## Idea

The sensor returns a fan of cells relative to the agent's heading. Writing them into the global map means rotating that fan by the heading and translating it by the position. Without this the agent has readings it cannot accumulate, and every step starts from nothing.

## Cost

O(k) per tick for k sensed cells. The rotation is a table lookup on the heading, not trigonometry.

## Where it is used

Shared by both agents; it is what turns a stream of local readings into the map the planners search over.

## Source

[`rescue-agents/src/auxiliar.cpp`](https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/auxiliar.cpp#L378-L472) &mdash; lines 378-401, 403-472.
