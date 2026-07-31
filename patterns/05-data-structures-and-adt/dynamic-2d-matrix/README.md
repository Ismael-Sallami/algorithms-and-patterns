# Dynamic two-dimensional matrix with manual memory

## Idea

A row-pointer array over a single contiguous block: one allocation for the data, one for the pointers. Indexing stays img[i][j] while the payload keeps cache locality and can be handed to an I/O routine as one buffer. Allocate and Destroy are written so that a half-built object is still safe to destroy.

## Cost

O(1) indexing. Allocation is two calls regardless of the number of rows, against one per row for an array of independently allocated rows.

## Where it is used

The Image ADT, which every operation in this category is built on.

## Source

[`image-adt/src/image.cpp`](https://github.com/Ismael-Sallami/image-adt/blob/main/src/image.cpp#L37) &mdash; lines 37-55, 59-65, 98-105.
