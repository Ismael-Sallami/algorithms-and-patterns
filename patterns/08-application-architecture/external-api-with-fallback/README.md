# Querying an external price API with a fallback

## Idea

Fetching quotes from a third-party API, converting to decimal, and leaving the last known price in place when the call fails. A network error must not become a zero in the portfolio: an absent update is recoverable, a wrong value written to the database is not.

## Cost

One request per symbol, with the previous value retained on failure.

## Where it is used

Portfolio valuation in the finance service.

## Source

[`personal-finance-manager/app/services/prices.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/prices.py#L1) &mdash; complete file.
