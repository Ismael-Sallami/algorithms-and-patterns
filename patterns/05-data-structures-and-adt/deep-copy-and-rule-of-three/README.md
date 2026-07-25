# Deep copy, assignment and destruction

## Idea

A class owning raw memory needs all three of copy constructor, copy assignment and destructor, or the compiler-generated versions will copy the pointer and produce a double free. Assignment additionally has to survive self-assignment and release the old buffer before taking the new one, in that order.

## Cost

O(rows x cols) per copy. The self-assignment guard is O(1).

## Where it is used

The Image ADT, which is passed and returned by value throughout.

## Source

[`TDA-Imagen/ej01_imagenes/estudiante/src/image.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/image.cpp#L75) &mdash; lines 75-81, 144-147, 151-153, 157-163.
