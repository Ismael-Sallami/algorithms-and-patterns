# Rotating a matrix by an arbitrary angle

## Idea

Rotation computed as an inverse mapping: for each output pixel, find where it came from in the input and sample there. Iterating over the output is what guarantees every output pixel gets a value - the forward mapping leaves holes wherever the rotation stretches the grid.

## Cost

O(h' x w') over the output, with a constant-cost trigonometric mapping and sample per pixel.

## Where it is used

Orienting the aircraft sprite along its route heading.

## Source

[`airline-routes-adt/src/pruebarotacion.cpp`](https://github.com/Ismael-Sallami/airline-routes-adt/blob/main/src/pruebarotacion.cpp#L5-L93) &mdash; complete file.
