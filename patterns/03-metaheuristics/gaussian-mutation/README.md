# Gaussian mutation with boundary handling

## Idea

Perturbs a real-valued gene by a normal deviate whose standard deviation is a fraction of the variable's range, then clips back into the feasible box. Scaling the deviation to the range keeps the operator meaningful when variables have different units; clipping keeps every offspring feasible so no repair pass is needed.

## Cost

O(1) per gene, O(n) per individual.

## Where it is used

Portfolio allocation: choose the weight of each asset to maximise risk-adjusted return, subject to per-asset bounds and weights that sum to one. Trained on 2015-2024 and tested on 2025.

## Source

[`metaheuristics/src/practice-2/src/gaussian_mutation.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-2/src/gaussian_mutation.cpp#L7-L87) &mdash; complete file.
