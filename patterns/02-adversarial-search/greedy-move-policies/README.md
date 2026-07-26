# Greedy and random move policies

## Idea

Three policies that make a move without building a tree: uniformly random, always advance the furthest piece, and pick the best immediate outcome by one-ply evaluation. They exist to measure what the search is worth - if the tree search cannot beat one-ply greedy by a clear margin, the extra depth is not paying for itself.

## Cost

O(1), O(p) and O(m) respectively, for p pieces and m legal moves. No recursion.

## Where it is used

Baseline opponents in the agent tournament.

## Source

[`Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp#L156) &mdash; lines 156-228, 260-298, 300-337.
