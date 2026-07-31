# Profit and loss over a position

## Idea

Realised and unrealised profit from the transaction history and the current price, in decimal arithmetic throughout. Binary floating point cannot represent monetary amounts exactly, so accumulating them there produces totals that are wrong by cents and never reconcile.

## Cost

O(t) for t transactions in the position.

## Where it is used

The portfolio return figures.

## Source

[`personal-finance-manager/app/services/pnl.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/pnl.py#L1-L43) &mdash; complete file.
