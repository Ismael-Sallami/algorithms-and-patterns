# Repeated-run protocol with mean and standard deviation

## Idea

A stochastic algorithm gives a different answer every run, so one run measures nothing. Each algorithm is run a fixed number of times from different seeds and reported as a mean with a standard deviation, and the per-run values are kept so the distributions can be compared rather than just their centres. Deterministic algorithms take the separate path, because averaging a single value is misleading.

## Cost

n runs times the per-run budget. The variance estimate is what n buys; the standard error falls as the square root of n.

## Where it is used

The comparison of all sixteen algorithms in this category.

## Source

[`MH-Practices/practice-3/code/main.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/main.cpp#L116) &mdash; lines 116-166, 169-194.
