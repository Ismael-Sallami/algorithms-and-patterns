# Producer-consumer with a FIFO buffer and counting semaphores

## Idea

The bounded buffer solved with three semaphores: one counting free slots, one counting occupied slots, one enforcing mutual exclusion on the indices. The two counting semaphores are what block a full producer and an empty consumer without either of them polling.

## Cost

O(1) per item. Throughput is bounded by the mutual exclusion section, not by the buffer size.

## Where it is used

Practice 1: same problem solved with FIFO and LIFO ordering to show that the synchronisation is independent of the buffer discipline.

## Source

[`SCD-Concurrency-MPI/src/Practica1/Primer-Ejercicio/prodcons-plantilla_FIFO.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica1/Primer-Ejercicio/prodcons-plantilla_FIFO.cpp#L1) &mdash; complete file.
