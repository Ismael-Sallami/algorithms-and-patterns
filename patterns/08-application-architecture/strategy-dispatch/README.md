# Dispatching to a parser by strategy

## Idea

One entry point that selects a parser by broker name and returns a common result type. Callers never learn which broker they are dealing with, so adding a broker is a new module and one table entry rather than an edit to every call site. The registry is the seam.

## Cost

O(1) dispatch. The cost is the parser's.

## Where it is used

Importing statements from several brokers into one account.

## Source

[`personal-finance-manager/app/services/parsers/dispatch.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/parsers/dispatch.py#L1-L29) &mdash; complete file.
