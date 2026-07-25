# Memetic algorithm

## Idea

A genetic algorithm that runs local search on its individuals every few generations. Crossover finds promising regions but leaves solutions rough; local search polishes them. Applying it to every individual every generation wastes the budget, so both the frequency and the fraction of the population treated are parameters.

## Cost

Genetic cost plus the local search budget times the number of individuals improved.

## Where it is used

Portfolio allocation: choose the weight of each asset to maximise risk-adjusted return, subject to per-asset bounds and weights that sum to one. Trained on 2015-2024 and tested on 2025.

## Source

[`MH-Practices/practice-3/code/src/memetic_algorithm.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/memetic_algorithm.cpp#L1) &mdash; complete file.
