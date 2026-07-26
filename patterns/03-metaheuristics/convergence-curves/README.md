# Convergence curves and boxplot comparison

## Idea

Plots best-so-far fitness against evaluations for every algorithm on one axis. A final number cannot distinguish a method that converges early and stalls from one that is still improving when the budget runs out, and those two want opposite decisions about the budget.

## Cost

O(a x e) points for a algorithms over e recorded evaluations.

## Where it is used

Analysis of the algorithm comparison.

## Source

[`MH-Practices/practice-3/EXTRA/convergencia_comparativa.py`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/EXTRA/convergencia_comparativa.py#L1) &mdash; complete file.
