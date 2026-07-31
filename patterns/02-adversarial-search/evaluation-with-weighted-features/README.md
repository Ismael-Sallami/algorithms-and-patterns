# Weighted linear evaluation over hand-picked features

## Idea

Features extracted separately and combined as a weighted sum. Making the weights explicit is what lets them be tuned by playing the agent against itself; folded into the arithmetic they cannot be. The structure is a linear model whose weights happen to be set by hand.

## Cost

O(p + f) per call for p pieces and f features.

## Where it is used

Third iteration of the Parchis agent.

## Source

[`parchis-ai/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L766-L874) &mdash; lines 766-874.
