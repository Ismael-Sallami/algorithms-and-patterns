# Adapter tolerating optional and renamed columns

## Idea

A broker export whose columns move between versions. The adapter resolves each field against a list of accepted names and fails loudly when a required one is missing, instead of silently producing a row with a hole in it. Third-party formats change without notice; the parser has to notice.

## Cost

O(rows x columns) for the resolution, dominated by the row pass.

## Where it is used

Importing broker statements.

## Source

[`personal-finance-manager/app/services/parsers/myinvestor.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/parsers/myinvestor.py#L1-L70) &mdash; complete file.
