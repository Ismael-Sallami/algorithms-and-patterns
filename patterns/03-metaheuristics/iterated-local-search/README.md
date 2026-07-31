# Iterated local search

## Idea

Instead of restarting from scratch, perturb the current best solution and re-optimise from there. The perturbation has to be strong enough to leave the current basin and weak enough to keep the structure that made the solution good. That balance is the whole design of the method.

## Cost

Same budget as multistart, spent on a guided walk between local optima rather than independent samples.

## Where it is used

Portfolio allocation: choose the weight of each asset to maximise risk-adjusted return, subject to per-asset bounds and weights that sum to one. Trained on 2015-2024 and tested on 2025.

## Source

[`metaheuristics/src/practice-3/src/ils.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-3/src/ils.cpp#L7-L72) &mdash; complete file.
