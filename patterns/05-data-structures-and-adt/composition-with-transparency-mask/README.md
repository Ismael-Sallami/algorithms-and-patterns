# Compositing one image onto another through a mask

## Idea

Pasting a sprite at an offset under two policies - opaque, which overwrites, and blended, which respects the transparency channel - together with the inverse operation that extracts a region back out. The destination rectangle is clipped, so a sprite crossing the edge is truncated rather than writing out of bounds.

## Cost

O(h x w) in the pasted region, independent of the canvas size.

## Where it is used

Drawing aircraft and country markers on the map.

## Source

[`airline-routes-adt/src/imagen.cpp`](https://github.com/Ismael-Sallami/airline-routes-adt/blob/main/src/imagen.cpp#L221-L264) &mdash; lines 221-238, 240-247, 249-264.
