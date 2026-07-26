# Multiple producers and consumers over a LIFO buffer

## Idea

The many-to-many buffer with stack discipline. Paired with the FIFO version to isolate one variable: the synchronisation is identical, so any difference in observed behaviour comes from the buffer order alone.

## Cost

O(1) per item. No bound on how long an item can remain buffered.

## Where it is used

Practice 1, second exercise.

## Source

[`SCD-Concurrency-MPI/src/Practica1/Segundo-Ejercicio/prodcons-multi-LIFO.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica1/Segundo-Ejercicio/prodcons-multi-LIFO.cpp#L1) &mdash; complete file.
