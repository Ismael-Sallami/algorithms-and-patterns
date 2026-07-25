# Single-index access over two-dimensional storage

## Idea

Exposing the buffer as a flat sequence, with the row and column recovered by division and modulus. Lets callers iterate over every pixel without knowing the geometry, which is what makes the whole-image operations short. The commented-out first version is kept above: it assumed one contiguous block and broke when the representation changed.

## Cost

O(1) per access, one integer division and one modulus.

## Where it is used

Used by the whole-image transforms in this category.

## Source

[`TDA-Imagen/ej01_imagenes/estudiante/src/image.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/image.cpp#L205) &mdash; lines 205-227.
