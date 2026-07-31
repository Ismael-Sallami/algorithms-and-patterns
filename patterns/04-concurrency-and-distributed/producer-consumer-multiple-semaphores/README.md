# Several producers and several consumers over one buffer

## Idea

Generalising to many threads on each side breaks the single-producer shortcut: the write index is now shared between producers and needs its own mutual exclusion, separate from the read index. Using one mutex for both would serialise producers against consumers for no reason.

## Cost

O(1) per item. Contention grows with the number of threads per side.

## Where it is used

Practice 1, third exercise.

## Source

[`concurrency-mpi/src/practice-1-semaphores/producer-consumer-multi/prodcons-multi-fifo.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-1-semaphores/producer-consumer-multi/prodcons-multi-fifo.cpp#L8-L131) &mdash; complete file.
