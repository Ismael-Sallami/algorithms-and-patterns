# Zoom by pixel replication and interpolation

## Idea

Doubling the resolution: original pixels land on even coordinates, and the gaps are filled by averaging their neighbours. Output geometry is 2n-1, not 2n, because interpolation happens between samples rather than after them - the classic off-by-one of every resampling routine.

## Cost

O(rows x cols) for the output, which is four times the input.

## Where it is used

The Zoom2X operation.

## Source

[`image-adt/src/imageop.cpp`](https://github.com/Ismael-Sallami/image-adt/blob/main/src/imageop.cpp#L117-L160) &mdash; lines 117-160.
