# Hand-written iterator over a 2D container

## Idea

An iterator pair that walks a row-pointer matrix as a single sequence, in both mutable and const form. Implementing dereference, increment and inequality is what makes the container work with range-based for and the standard algorithms, without exposing the layout.

## Cost

O(1) per step. Traversal is O(rows x cols) with no allocation.

## Where it is used

The Imagen container in the air routes project.

## Source

[`Air-lines-Project/rutas_aereas/src/imagen.cpp`](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/src/imagen.cpp#L1) &mdash; lines 1-65.
