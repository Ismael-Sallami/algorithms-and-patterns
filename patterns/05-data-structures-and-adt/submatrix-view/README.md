# Cropping a submatrix

## Idea

Extracting a rectangular region into a new object, with the requested region clipped against the source bounds instead of trusted. Copying rather than aliasing keeps the result independent of the source's lifetime, which matters because the ADT owns its memory.

## Cost

O(height x width), independent of the source size.

## Where it is used

The Crop operation.

## Source

[`image-adt/src/imageop.cpp`](https://github.com/Ismael-Sallami/image-adt/blob/main/src/imageop.cpp#L71-L84) &mdash; lines 71-84.
