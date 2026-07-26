# Signal-and-continue monitor semantics

## Idea

Under signal-and-continue the signalling thread keeps the monitor, so by the time the woken thread runs, the condition it was signalled about may already be false again. Every wait therefore has to sit in a loop that re-checks. The same code without the loop is a race that appears only under contention.

## Cost

O(1) per operation plus the cost of spurious wakeups, which grows with the number of waiters.

## Where it is used

Practice 3, contrasted with the signal-and-urgent version.

## Source

[`SCD-Concurrency-MPI/src/Practica3/scd-p3-fuentes/prodcons.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica3/scd-p3-fuentes/prodcons.cpp#L1) &mdash; complete file.
