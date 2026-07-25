# Minimax over a game tree

## Idea

Depth-first recursion that alternates between maximising and minimising levels, returning the evaluation of the best reachable leaf under the assumption that the opponent plays as well as we do. At the root the chosen move is written back through reference parameters, which avoids carrying a move stack down the recursion.

## Cost

O(b^d) time for branching factor b and depth d, O(d) stack space.

## Where it is used

Baseline for the Parchis agent, kept as the reference the pruned versions are checked against: both must return the same value.

## Source

[`Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp#L401) &mdash; lines 401-454.
