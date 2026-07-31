# Reading and writing PPM and PGM files

## Idea

Both the grey and the colour variants of the format, sharing one header parser and differing in bytes per pixel. Detecting the magic number and dispatching on it means a caller can load either without knowing which it has, which is what the compositing code relies on.

## Cost

O(size) per file with a single pass over the payload.

## Where it is used

Loading map, aircraft and flag images.

## Source

[`airline-routes-adt/src/imagenES.cpp`](https://github.com/Ismael-Sallami/airline-routes-adt/blob/main/src/imagenES.cpp#L1-L160) &mdash; complete file.
