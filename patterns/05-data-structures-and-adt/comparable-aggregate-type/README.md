# Aggregate type ordered by one field

## Idea

An aggregate holding a name, a coordinate and a flag, ordered by name alone. That choice is what makes lookup by name logarithmic and lookup by coordinate linear in the container built over it - the ordering is the index, and it can only serve one query.

## Cost

O(1) per comparison; the container's complexity follows from it.

## Where it is used

The country type in the air routes project.

## Source

[`Air-lines-Project/rutas_aereas/src/Pais.cpp`](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/src/Pais.cpp#L1) &mdash; complete file.
