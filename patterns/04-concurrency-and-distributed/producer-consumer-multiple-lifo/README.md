# Multiple producers and consumers over a LIFO buffer

## Idea

The many-to-many buffer with stack discipline. Paired with the FIFO version to isolate one variable: the synchronisation is identical, so any difference in observed behaviour comes from the buffer order alone.

## Cost

O(1) per item. No bound on how long an item can remain buffered.

## Where it is used

Practice 1, second exercise.

## Source

[`concurrency-mpi/src/practice-1-semaphores/producer-consumer-multi/prodcons-multi-lifo.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-1-semaphores/producer-consumer-multi/prodcons-multi-lifo.cpp#L8-L131) &mdash; complete file.
