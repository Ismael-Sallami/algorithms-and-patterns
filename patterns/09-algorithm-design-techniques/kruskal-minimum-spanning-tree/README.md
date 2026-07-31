# Kruskal with union-find over the streets of a village

## Idea

Pave as few streets as possible so that every square is still reachable from every other. Sort the streets by cost and take each one unless it would close a cycle, which union-find answers in almost constant time. The cycle test is the whole algorithm: without it this is just a sorted list.

## Cost

O(E log E) dominated by the sort; the union-find operations are effectively constant.

## Where it is used

Practical 3 of Algorithmics. The program also writes the graph and the resulting tree as DOT files, so the answer can be looked at rather than read.

## Source

[`src/02-greedy/street_paving.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/02-greedy/street_paving.cpp#L84) &mdash; lines 84-107.
