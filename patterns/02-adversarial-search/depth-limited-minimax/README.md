# Minimax with a hard node budget

## Idea

Minimax that stops on either of two conditions: the depth limit or an exhausted node budget. Under a per-move time limit an unbounded search is useless, because a deep branch can consume the whole budget before any sibling is looked at. Cutting on node count trades completeness for a guaranteed answer.

## Cost

O(min(b^d, N)) where N is the node budget.

## Where it is used

Used when the engine enforces a per-move time limit.

## Source

[`Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp#L458) &mdash; lines 458-521.
