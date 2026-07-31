# Iterated local search with simulated annealing as the local optimiser

## Idea

The local optimiser inside ILS is replaced by simulated annealing, so the inner phase can itself escape small basins instead of stopping at the first local optimum. Two escape mechanisms at two scales: annealing handles the small ones, the ILS perturbation handles the large ones.

## Cost

Cost is the ILS iteration count times the annealing budget per iteration.

## Where it is used

Portfolio allocation: choose the weight of each asset to maximise risk-adjusted return, subject to per-asset bounds and weights that sum to one. Trained on 2015-2024 and tested on 2025.

## Source

[`metaheuristics/src/practice-3/src/ils_es.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-3/src/ils_es.cpp#L3-L38) &mdash; complete file.
