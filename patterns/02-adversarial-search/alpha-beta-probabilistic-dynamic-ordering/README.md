# Probabilistic alpha-beta with depth-dependent ordering

## Idea

Combines the previous two ideas and makes the ordering effort depend on depth. Sorting near the root is worth it because a cut there removes a large subtree; sorting near the leaves costs more than it saves. So the sort is applied only above a depth threshold.

## Cost

Same asymptotics as probabilistic alpha-beta with a smaller constant, because the O(b log b) sort is no longer paid at every level.

## Where it is used

The strongest configuration of the agent.

## Source

[`parchis-ai/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L1213-L1277) &mdash; lines 1213-1277.
