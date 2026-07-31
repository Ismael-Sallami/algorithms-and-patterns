# Local search, best improvement

## Idea

Evaluates the whole neighbourhood and moves to the best neighbour. Each step is the largest available, but each step costs a full neighbourhood scan. Against first improvement it usually needs fewer steps and more evaluations, and it converges to a different local optimum.

## Cost

O(|N|) evaluations per step, always.

## Where it is used

Portfolio allocation: choose the weight of each asset to maximise risk-adjusted return, subject to per-asset bounds and weights that sum to one. Trained on 2015-2024 and tested on 2025.

## Source

[`metaheuristics/src/practice-2/src/localsearch_best.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-2/src/localsearch_best.cpp#L8-L88) &mdash; complete file.
