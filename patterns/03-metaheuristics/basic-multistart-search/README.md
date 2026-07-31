# Basic multistart with a shared best

## Idea

Multistart with the bookkeeping made explicit: each restart is fully independent, and only the best solution found across all of them survives. Serves as the control experiment for iterated local search, which differs from it in exactly one respect - restarts are perturbations of the current best rather than fresh random points.

## Cost

Linear in the number of restarts. Memory is O(1) beyond the current and best solutions.

## Where it is used

Portfolio allocation: choose the weight of each asset to maximise risk-adjusted return, subject to per-asset bounds and weights that sum to one. Trained on 2015-2024 and tested on 2025.

## Source

[`metaheuristics/src/practice-3/src/bmb.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-3/src/bmb.cpp#L4-L34) &mdash; complete file.
