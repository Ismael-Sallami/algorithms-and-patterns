# Single-index access over two-dimensional storage

## Idea

Exposing the buffer as a flat sequence, with the row and column recovered by division and modulus. Lets callers iterate over every pixel without knowing the geometry, which is what makes the whole-image operations short. The commented-out first version is kept above: it assumed one contiguous block and broke when the representation changed.

## Cost

O(1) per access, one integer division and one modulus.

## Where it is used

Used by the whole-image transforms in this category.

## Source

[`image-adt/src/image.cpp`](https://github.com/Ismael-Sallami/image-adt/blob/main/src/image.cpp#L208-L226) &mdash; lines 205-227.
