# Baseline evaluation function

## Idea

The first evaluation written for the agent: distance travelled by each piece, differenced between the two sides. Deliberately crude, and kept because it is the control - any later evaluation has to beat this one in head-to-head play, not just look more sophisticated.

## Cost

O(p) per call for p pieces.

## Where it is used

Reference opponent for every later evaluation in this category.

## Source

[`Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp#L342) &mdash; lines 342-398.
