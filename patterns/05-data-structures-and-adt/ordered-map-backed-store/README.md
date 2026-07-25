# Associative store over an ordered map

## Idea

A container that stores routes keyed by code in a std::map, wrapped so that callers see a domain interface rather than map iterators. The wrapping is what lets the underlying container be replaced without touching call sites, and it keeps the class's invariants enforceable in one place.

## Cost

O(log n) insert, erase and lookup. Iteration is O(n) in key order, which the map gives for free.

## Where it is used

The route store in the air routes project.

## Source

[`Air-lines-Project/rutas_aereas/src/Almacen_Rutas.cpp`](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/src/Almacen_Rutas.cpp#L1) &mdash; complete file.
