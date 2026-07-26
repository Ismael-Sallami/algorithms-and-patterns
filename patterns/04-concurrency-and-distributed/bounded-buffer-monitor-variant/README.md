# Bounded buffer monitor with separate full and empty conditions

## Idea

Two condition variables instead of one. With a single condition every signal wakes an arbitrary waiter, so a producer can wake another producer and the useful wakeup is lost. Splitting the conditions means each signal reaches a thread that can actually make progress.

## Cost

O(1) per operation, with each signal waking exactly one thread that can proceed.

## Where it is used

Practice 3.

## Source

[`SCD-Concurrency-MPI/src/Practica3/scd-p3-fuentes/prodcons2.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica3/scd-p3-fuentes/prodcons2.cpp#L1) &mdash; complete file.
