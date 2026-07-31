# Producer-consumer with a LIFO buffer

## Idea

The same three semaphores over a stack instead of a queue. Correctness of the synchronisation does not change, but the order items are delivered in does, and so does the worst-case time an item can sit in the buffer - under sustained load a LIFO buffer can starve its oldest entry indefinitely.

## Cost

O(1) per item. No fairness guarantee on item age.

## Where it is used

Practice 1, paired with the FIFO version.

## Source

[`concurrency-mpi/src/practice-1-semaphores/producer-consumer/prodcons-lifo.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-1-semaphores/producer-consumer/prodcons-lifo.cpp#L8-L160) &mdash; complete file.
