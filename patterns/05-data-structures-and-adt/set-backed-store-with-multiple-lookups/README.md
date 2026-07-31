# Set-backed store with lookup by two different keys

## Idea

Countries kept in a std::set ordered by name, with two find overloads: by country and by map coordinate. The first uses the set's ordering and is logarithmic; the second cannot, because the set is not ordered by position, so it degrades to a linear scan. The asymmetry is the point - one index serves one query pattern.

## Cost

O(log n) lookup by name, O(n) lookup by coordinate.

## Where it is used

The country collection in the air routes project.

## Source

[`airline-routes-adt/src/Paises.cpp`](https://github.com/Ismael-Sallami/airline-routes-adt/blob/main/src/Paises.cpp#L2-L134) &mdash; complete file.
