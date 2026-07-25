# A* re-targeted at a resupply point when the primary goal is unreachable

## Idea

The same A* core, but the goal test is parameterised: when the agent runs low on battery the search switches to the nearest recharge cell instead of the mission target, and the destination is written back to the caller. This turns a fixed-goal search into a search over a set of acceptable goals without duplicating the expansion loop.

## Cost

O((V + E) log V). Searching for the nearest member of a goal set costs the same as searching for a single goal; the test is O(1) per node.

## Where it is used

Level 4 of the auxiliary agent, which has a battery budget and has to interleave its mission with recharging.

## Source

[`Practica2_IA/practica2/auxiliar.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/auxiliar.cpp#L1302) &mdash; lines 1302-1396.
