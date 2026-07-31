# Dining philosophers, correct solution

## Idea

Five philosophers, five forks, each needs both neighbours' forks. Deadlock is avoided by breaking the symmetry of the circular wait: one philosopher picks its forks up in the opposite order. Removing any single edge from the wait-for cycle is enough.

## Cost

O(1) per meal. At most two philosophers eat at once.

## Where it is used

Practice 3.

## Source

[`concurrency-mpi/src/practice-3-mpi/philosophers.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-3-mpi/philosophers.cpp#L15-L141) &mdash; complete file.
