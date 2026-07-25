# Differential evolution

## Idea

Builds each candidate from the weighted difference of population members rather than from a fixed mutation distribution. The step size therefore comes from the population's own spread: large while the population is scattered, small once it has converged. Self-scaling without a schedule.

## Cost

O(g x p) evaluations. One trial vector per member per generation.

## Where it is used

Portfolio allocation: choose the weight of each asset to maximise risk-adjusted return, subject to per-asset bounds and weights that sum to one. Trained on 2015-2024 and tested on 2025.

## Source

[`MH-Practices/practice-3/code/src/differential_evolution.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/differential_evolution.cpp#L1) &mdash; complete file.
