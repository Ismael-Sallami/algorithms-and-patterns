# Simulated annealing

## Idea

Accepts worsening moves with probability exp(-delta/T) and lowers T over time. Early on the walk is close to random and can cross barriers; late on it behaves like a hill climber. The cooling schedule is what decides whether the run explores or exploits, and it is the parameter that matters most.

## Cost

O(iterations) evaluations, one per candidate. Memory O(1).

## Where it is used

Portfolio allocation: choose the weight of each asset to maximise risk-adjusted return, subject to per-asset bounds and weights that sum to one. Trained on 2015-2024 and tested on 2025.

## Source

[`MH-Practices/practice-3/code/src/simulated_annealing.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/simulated_annealing.cpp#L1) &mdash; complete file.
