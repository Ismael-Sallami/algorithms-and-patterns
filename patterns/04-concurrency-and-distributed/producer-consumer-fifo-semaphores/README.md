# Producer-consumer with a FIFO buffer and counting semaphores

## Idea

The bounded buffer solved with three semaphores: one counting free slots, one counting occupied slots, one enforcing mutual exclusion on the indices. The two counting semaphores are what block a full producer and an empty consumer without either of them polling.

## Cost

O(1) per item. Throughput is bounded by the mutual exclusion section, not by the buffer size.

## Where it is used

Practice 1: same problem solved with FIFO and LIFO ordering to show that the synchronisation is independent of the buffer discipline.

## Source

[`concurrency-mpi/src/practice-1-semaphores/producer-consumer/prodcons-fifo.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-1-semaphores/producer-consumer/prodcons-fifo.cpp#L8-L169) &mdash; complete file.
