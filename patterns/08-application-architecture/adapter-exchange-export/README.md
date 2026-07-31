# Adapter for an exchange CSV export

## Idea

Maps one exchange's export onto the internal transaction type: its column names, its timestamp format, its sign conventions for buys and sells. The adapter absorbs the format so nothing downstream has to know it existed.

## Cost

O(rows) with one pass.

## Where it is used

Importing cryptocurrency exchange statements.

## Source

[`personal-finance-manager/app/services/parsers/kraken.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/parsers/kraken.py#L1-L49) &mdash; complete file.
