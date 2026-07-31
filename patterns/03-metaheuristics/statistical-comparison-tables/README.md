# Generating comparison tables across algorithms

## Idea

Collects the per-run results of every algorithm and emits the ranked comparison tables. Reporting train and test figures side by side is what exposes the methods that overfit the training window - the ones whose training score is best and whose test score is not.

## Cost

O(a x r) for a algorithms and r runs each.

## Where it is used

Producing the results section of the practical reports.

## Source

[`metaheuristics/src/practice-3/extra/generar_tablas_comparativas.py`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-3/extra/generar_tablas_comparativas.py#L2-L168) &mdash; complete file.
