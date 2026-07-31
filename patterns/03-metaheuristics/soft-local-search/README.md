# Bounded-intensity local search

## Idea

Local search stopped well before convergence, on a fixed small number of evaluations. Used as the refinement operator inside the memetic algorithms, where running local search to convergence would consume the whole budget on a handful of individuals.

## Cost

O(k) evaluations for a fixed k, by construction.

## Where it is used

Portfolio allocation: choose the weight of each asset to maximise risk-adjusted return, subject to per-asset bounds and weights that sum to one. Trained on 2015-2024 and tested on 2025.

## Source

[`metaheuristics/src/practice-2/src/soft_local_search.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-2/src/soft_local_search.cpp#L7-L112) &mdash; complete file.
