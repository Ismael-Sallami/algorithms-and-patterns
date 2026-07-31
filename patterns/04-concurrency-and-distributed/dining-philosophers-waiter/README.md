# Dining philosophers with a waiter

## Idea

A separate waiter process admits at most four philosophers to the table. With one seat always free the circular wait cannot close, so deadlock is impossible without asymmetric fork ordering. A different fix for the same problem: bound the resource demand instead of breaking the cycle.

## Cost

O(1) per meal, with the waiter as an extra serialisation point.

## Where it is used

Practice 3.

## Source

[`concurrency-mpi/src/practice-3-mpi/philosophers-waiter.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-3-mpi/philosophers-waiter.cpp#L21-L173) &mdash; complete file.
