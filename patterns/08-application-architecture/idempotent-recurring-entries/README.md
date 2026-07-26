# Generating recurring entries idempotently

## Idea

Recurring contributions materialised into real rows, with a check that the row for a period does not already exist. Without that check a job that runs twice - a retry, a restart, an overlapping schedule - books the same contribution twice, and nothing downstream can tell the duplicate from a real one.

## Cost

O(p) for p periods due, with an indexed existence check per period.

## Where it is used

Monthly investment contributions.

## Source

[`personal-finance-manager/app/services/contributions.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/contributions.py#L1) &mdash; complete file.
