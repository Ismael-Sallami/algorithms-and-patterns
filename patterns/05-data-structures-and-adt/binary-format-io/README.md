# Reading and writing a binary PGM file

## Idea

Parsing a header of unknown length - magic number, optional comments, whitespace, dimensions, maximum value - and then reading the payload as one block. Whitespace and comment skipping is factored into its own routine because the header grammar allows them between any two tokens.

## Cost

O(size) for the payload; the header is bounded and read character by character.

## Where it is used

Persistence for the Image ADT.

## Source

[`TDA-Imagen/ej01_imagenes/estudiante/src/imageIO.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/imageIO.cpp#L1) &mdash; complete file.
