# Hybrid of iterated local search, annealing and a CHC population

## Idea

Adds a population with CHC-style incest prevention and elitist replacement on top of the previous hybrid. CHC only crosses parents that are far enough apart in the search space, which delays convergence and keeps diversity alive long enough for the annealing phase to be worth running.

## Cost

Population size times generations, plus the annealing budget. The most expensive method in this category per unit of improvement.

## Where it is used

Portfolio allocation: choose the weight of each asset to maximise risk-adjusted return, subject to per-asset bounds and weights that sum to one. Trained on 2015-2024 and tested on 2025.

## Source

[`MH-Practices/practice-3/code/src/ils_es_chc.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/ils_es_chc.cpp#L1) &mdash; complete file.
