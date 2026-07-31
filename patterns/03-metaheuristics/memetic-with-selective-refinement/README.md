# Memetic algorithm refining only the best individuals

## Idea

Variant that spends the local search budget on the best individuals instead of a random sample. It converges faster and loses diversity faster, so it is the direct counterpart to the previous file in the experimental comparison.

## Cost

Same order as the memetic algorithm; the constant is lower because fewer individuals are refined.

## Where it is used

Portfolio allocation: choose the weight of each asset to maximise risk-adjusted return, subject to per-asset bounds and weights that sum to one. Trained on 2015-2024 and tested on 2025.

## Source

[`metaheuristics/src/practice-2/src/memetic_lsch.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-2/src/memetic_lsch.cpp#L6-L149) &mdash; complete file.
