# Window mean and subsampling

## Idea

Subsampling by an integer factor, where each output pixel is the mean of the input window it covers. Averaging before discarding is what stops the result from aliasing, which is exactly what taking every k-th pixel would do. Mean is factored out so it can also be used on its own.

## Cost

O(rows x cols) overall: every input pixel is read once regardless of the factor.

## Where it is used

The Subsample operation, and the icon generator built on it.

## Source

[`TDA-Imagen/ej01_imagenes/estudiante/src/imageop.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/imageop.cpp#L43) &mdash; lines 43-51, 54-68.
