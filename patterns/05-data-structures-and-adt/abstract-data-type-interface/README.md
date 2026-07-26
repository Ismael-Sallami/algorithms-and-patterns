# Designing the interface of an ADT

## Idea

The header is the contract: which invariants hold, which operations are const, what each one does at the boundaries. Splitting the private helpers that manage memory from the public operations that use them is what keeps the invariant - rows, columns and buffer always consistent - enforceable in one place.

## Cost

Declarations only. The costs of the operations are documented alongside them.

## Where it is used

The contract for every operation catalogued from this repository.

## Source

[`TDA-Imagen/ej01_imagenes/estudiante/include/image.h`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/include/image.h#L1) &mdash; complete file.
