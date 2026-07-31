# Greedy refuelling: always the furthest station still reachable

## Idea

A bus can do k kilometres on a tank and wants to stop as few times as possible. At each station, look ahead and pick the furthest one still within range. It is the textbook exchange argument: any solution that stops earlier can be rewritten to stop at the furthest reachable station without ever needing more stops, so the greedy choice is safe and the result is optimal.

## Cost

O(n) over the stations, each one considered once.

## Where it is used

Practical 3 of Algorithmics, the problem where greedy is provably optimal, unlike the two that open the same practical.

## Source

[`src/02-greedy/bus_refuelling.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/02-greedy/bus_refuelling.cpp#L26) &mdash; lines 26-52.
