# Evaluation function with weights that follow the game phase

## Idea

Everything the search depends on for its numbers. The position is scored per player and the scores are subtracted, so the function is zero-sum by construction and cannot prefer a move that helps both sides. The feature weights change with the phase of the game: safety matters at the start, progress towards home matters at the end.

## Cost

O(p) per call for p pieces, called once per leaf. Since leaves dominate the node count, this is the hot path of the whole search.

## Where it is used

Shared by every search variant in this category through the Heuristic interface, which is what lets them be compared on equal terms.

## Source

[`parchis-ai/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L940) &mdash; lines 940-1007, 1009-1022, 1434-1463.
