# Aggregating transactions into report figures

## Idea

Turning a transaction log into per-period, per-category and per-account totals in one pass, with the grouping keys computed once. Each figure the dashboard shows is a different reduction over the same stream, so doing them together costs one traversal instead of one per figure.

## Cost

O(n) over the transactions, O(g) memory for g groups.

## Where it is used

The dashboard and the monthly reports.

## Source

[`personal-finance-manager/app/services/aggregation.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/aggregation.py#L1-L292) &mdash; complete file.
