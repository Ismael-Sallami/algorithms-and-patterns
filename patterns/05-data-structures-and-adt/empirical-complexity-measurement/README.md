# Measuring an algorithm's cost empirically

## Idea

Timing the same operation across growing input sizes and fitting the result, to check that the measured curve matches the predicted order. Answers what the asymptotic analysis cannot: where the constants stop mattering, and whether the implementation actually has the complexity its structure suggests.

## Cost

The harness is O(1) over the measurement; what it produces is the growth curve of the operation under test.

## Where it is used

Efficiency study of the row permutation above.

## Source

[`TDA-Imagen/ej05_eficiencia/barajar_puntos_1_5.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej05_eficiencia/barajar_puntos_1_5.cpp#L1) &mdash; complete file.
