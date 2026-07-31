# Composing transforms into a pipeline

## Idea

Building a thumbnail by chaining existing operations rather than writing a dedicated routine. Each stage returns a new image, so the pipeline is a sequence of value-returning calls with no shared mutable state - which is only affordable because the ADT's copy semantics are correct.

## Cost

O(rows x cols) overall, dominated by the first pass over the full-size input.

## Where it is used

The icon generator built on the image ADT.

## Source

[`image-adt/src/icono.cpp`](https://github.com/Ismael-Sallami/image-adt/blob/main/src/icono.cpp#L11-L58) &mdash; complete file.
