# Producer-consumer with a LIFO buffer

## Idea

The same three semaphores over a stack instead of a queue. Correctness of the synchronisation does not change, but the order items are delivered in does, and so does the worst-case time an item can sit in the buffer - under sustained load a LIFO buffer can starve its oldest entry indefinitely.

## Cost

O(1) per item. No fairness guarantee on item age.

## Where it is used

Practice 1, paired with the FIFO version.

## Source

[`SCD-Concurrency-MPI/src/Practica1/Primer-Ejercicio/prodcons-plantilla_LIFO.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica1/Primer-Ejercicio/prodcons-plantilla_LIFO.cpp#L1) &mdash; complete file.
