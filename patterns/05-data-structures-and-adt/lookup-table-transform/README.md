# Contrast adjustment through a lookup table

## Idea

A piecewise-linear intensity mapping precomputed into a 256-entry table, then applied by lookup. The mapping is fixed per call and the domain is small, so computing it once and indexing beats recomputing it per pixel. The same idea applies to any bounded-domain pointwise function.

## Cost

O(256 + rows x cols) instead of O(rows x cols) arithmetic evaluations. The table cost is constant.

## Where it is used

Contrast stretching in the image ADT.

## Source

[`TDA-Imagen/ej01_imagenes/estudiante/src/imageop.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/imageop.cpp#L24) &mdash; lines 24-40.
