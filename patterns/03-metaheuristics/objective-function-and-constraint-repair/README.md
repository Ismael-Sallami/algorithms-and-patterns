# Objective function with constraint repair

## Idea

The problem definition shared by all sixteen algorithms above: decode a vector into portfolio weights, repair it so the weights respect their bounds and sum to one, then score it. Repairing inside the objective means every algorithm sees a feasible space and none of them needs its own penalty term - which is also what makes the comparison between them fair.

## Cost

O(n) per evaluation for n assets, plus the cost of scoring against the historical series.

## Where it is used

Portfolio allocation: choose the weight of each asset to maximise risk-adjusted return, subject to per-asset bounds and weights that sum to one. Trained on 2015-2024 and tested on 2025.

## Source

[`metaheuristics/src/practice-2/src/portfolio_problem.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-2/src/portfolio_problem.cpp#L5-L210) &mdash; complete file.
