# Bounded buffer monitor with separate full and empty conditions

## Idea

Two condition variables instead of one. With a single condition every signal wakes an arbitrary waiter, so a producer can wake another producer and the useful wakeup is lost. Splitting the conditions means each signal reaches a thread that can actually make progress.

## Cost

O(1) per operation, with each signal waking exactly one thread that can proceed.

## Where it is used

Practice 3.

## Source

[`concurrency-mpi/src/practice-3-mpi/producer-consumer-buffer.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-3-mpi/producer-consumer-buffer.cpp#L22-L176) &mdash; complete file.
