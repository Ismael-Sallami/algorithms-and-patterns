# Local search, first improvement

## Idea

Explores the neighbourhood of the current solution and moves as soon as any neighbour is better, without looking at the rest. Accepting early means more moves per unit of budget; the path through the space is longer but each step is cheaper.

## Cost

Unbounded number of iterations in theory, bounded by the evaluation budget in practice. Expected O(|N|/2) evaluations per step for neighbourhood N.

## Where it is used

Portfolio allocation: choose the weight of each asset to maximise risk-adjusted return, subject to per-asset bounds and weights that sum to one. Trained on 2015-2024 and tested on 2025.

## Source

[`metaheuristics/src/practice-3/src/localsearch.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-3/src/localsearch.cpp#L7-L87) &mdash; complete file.
