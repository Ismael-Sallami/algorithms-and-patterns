# Hand-written iterator over a 2D container

## Idea

An iterator pair that walks a row-pointer matrix as a single sequence, in both mutable and const form. Implementing dereference, increment and inequality is what makes the container work with range-based for and the standard algorithms, without exposing the layout.

## Cost

O(1) per step. Traversal is O(rows x cols) with no allocation.

## Where it is used

The Imagen container in the air routes project.

## Source

[`airline-routes-adt/src/imagen.cpp`](https://github.com/Ismael-Sallami/airline-routes-adt/blob/main/src/imagen.cpp#L6-L65) &mdash; lines 1-65.
