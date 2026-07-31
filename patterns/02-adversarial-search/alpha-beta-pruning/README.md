# Alpha-beta pruning

## Idea

Minimax carrying the best value the maximiser is already guaranteed (alpha) and the best the minimiser is already guaranteed (beta). When the two windows cross, the rest of the current node's children cannot change the result and are skipped. The returned value is identical to plain minimax; only the number of visited nodes changes.

## Cost

Between O(b^(d/2)) with perfect move ordering and O(b^d) with the worst ordering. The square root in the best case is what makes the extra depth affordable.

## Where it is used

Main search of the Parchis agent.

## Source

[`parchis-ai/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L530-L613) &mdash; lines 530-613.
