# Local search, first improvement

## Idea

Explores the neighbourhood of the current solution and moves as soon as any neighbour is better, without looking at the rest. Accepting early means more moves per unit of budget; the path through the space is longer but each step is cheaper.

## Cost

Unbounded number of iterations in theory, bounded by the evaluation budget in practice. Expected O(|N|/2) evaluations per step for neighbourhood N.

## Where it is used

Portfolio allocation: choose the weight of each asset to maximise risk-adjusted return, subject to per-asset bounds and weights that sum to one. Trained on 2015-2024 and tested on 2025.

## Source

[`MH-Practices/practice-3/code/src/localsearch.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/localsearch.cpp#L1) &mdash; complete file.
