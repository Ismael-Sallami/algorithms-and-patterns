# Signal-and-continue monitor semantics

## Idea

Under signal-and-continue the signalling thread keeps the monitor, so by the time the woken thread runs, the condition it was signalled about may already be false again. Every wait therefore has to sit in a loop that re-checks. The same code without the loop is a race that appears only under contention.

## Cost

O(1) per operation plus the cost of spurious wakeups, which grows with the number of waiters.

## Where it is used

Practice 3, contrasted with the signal-and-urgent version.

## Source

[`concurrency-mpi/src/practice-3-mpi/producer-consumer.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-3-mpi/producer-consumer.cpp#L22-L140) &mdash; complete file.
