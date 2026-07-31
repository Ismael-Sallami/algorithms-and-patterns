# Probabilistic cutoff in a chance node tree

## Idea

The dice make the tree contain chance nodes, so a branch's contribution is weighted by its probability. Branches whose probability falls below epsilon are dropped without being expanded. The result is no longer exact, which is the point: spending the budget on the likely part of the tree beats an exact answer over a shallower horizon.

## Cost

Expected cost falls with epsilon. The pruned mass is bounded by the total probability of the discarded branches, so epsilon is a direct knob on the accuracy-versus-depth trade.

## Where it is used

Enabled when the agent is configured for deeper search under the same time limit.

## Source

[`parchis-ai/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L1139-L1207) &mdash; lines 1139-1207.
