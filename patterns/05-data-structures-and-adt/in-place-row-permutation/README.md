# In-place row permutation

## Idea

Permutes the rows by swapping row pointers, not row contents. Because the matrix is a pointer array over a data block, a full row moves in one pointer assignment - the payload never moves. Indirection turning an O(n) move into O(1) is the whole reason for the representation.

## Cost

O(rows) swaps and no data movement, against O(rows x cols) byte copies for a flat layout.

## Where it is used

The ShuffleRows operation, and the subject of the efficiency study below.

## Source

[`TDA-Imagen/ej01_imagenes/estudiante/src/imageop.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/imageop.cpp#L104) &mdash; lines 104-113.
