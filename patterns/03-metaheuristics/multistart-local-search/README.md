# Multistart local search

## Idea

Local search is deterministic once the start point is fixed, so it can only reach the local optimum in whose basin it started. Restarting from independent random points samples several basins and keeps the best result. The simplest way to add global reach to a local method.

## Cost

k independent runs; the budget is split k ways, so each run is shallower. Choosing k trades breadth against depth.

## Where it is used

Portfolio allocation: choose the weight of each asset to maximise risk-adjusted return, subject to per-asset bounds and weights that sum to one. Trained on 2015-2024 and tested on 2025.

## Source

[`MH-Practices/practice-3/code/src/localsearch_multistart.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/localsearch_multistart.cpp#L1) &mdash; complete file.
