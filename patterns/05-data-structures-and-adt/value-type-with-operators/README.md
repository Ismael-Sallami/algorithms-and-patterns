# Value type with comparison and I/O operators

## Idea

A coordinate as a value type: comparison, equality and stream operators, no identity and no ownership. Giving it a total order is what lets it be a key in an ordered container, and it is the reason the containers built on it get logarithmic lookup for free.

## Cost

O(1) for every operation.

## Where it is used

The coordinate type underlying routes and countries.

## Source

[`airline-routes-adt/src/Punto.cpp`](https://github.com/Ismael-Sallami/airline-routes-adt/blob/main/src/Punto.cpp#L3-L54) &mdash; complete file.
