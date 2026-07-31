# Adapter for a multi-section document

## Idea

The hardest of the three: one document containing several kinds of record, so parsing is a small state machine over the sections rather than a row loop. Each section maps to a different transaction type, and the state machine is what keeps that from becoming a chain of conditionals.

## Cost

O(lines) with one pass and constant state.

## Where it is used

Importing broker statements.

## Source

[`personal-finance-manager/app/services/parsers/traderepublic.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/parsers/traderepublic.py#L1-L169) &mdash; complete file.
