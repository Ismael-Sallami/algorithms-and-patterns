# Genetic algorithm, generational and steady-state

## Idea

Population-based search with selection, crossover and mutation. Both replacement schemes are implemented: generational, which replaces the whole population each round with elitism to protect the best individual, and steady-state, which replaces only the two worst. Crossover is BLX-alpha, which suits real-valued genes because it interpolates and extrapolates between parents instead of swapping segments.

## Cost

O(g x p x c) for g generations, p individuals and c cost per evaluation. Evaluation dominates.

## Where it is used

Portfolio allocation: choose the weight of each asset to maximise risk-adjusted return, subject to per-asset bounds and weights that sum to one. Trained on 2015-2024 and tested on 2025.

## Source

[`MH-Practices/practice-3/code/src/genetic_algorithm.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/genetic_algorithm.cpp#L1) &mdash; complete file.
