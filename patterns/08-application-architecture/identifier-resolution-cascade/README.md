# Resolving an identifier through a cascade of sources

## Idea

Mapping an ISIN to a tradeable ticker by trying several providers in order and taking the first plausible answer, with the selection rules explicit. No single source covers every instrument, and the cascade is what turns partial coverage from each into usable coverage overall.

## Cost

Worst case one request per provider; the common case stops at the first.

## Where it is used

Instrument identification when importing statements.

## Source

[`personal-finance-manager/app/services/symbol_lookup.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/symbol_lookup.py#L1-L134) &mdash; complete file.
