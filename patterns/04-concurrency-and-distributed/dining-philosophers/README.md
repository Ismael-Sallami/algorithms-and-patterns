# Dining philosophers, correct solution

## Idea

Five philosophers, five forks, each needs both neighbours' forks. Deadlock is avoided by breaking the symmetry of the circular wait: one philosopher picks its forks up in the opposite order. Removing any single edge from the wait-for cycle is enough.

## Cost

O(1) per meal. At most two philosophers eat at once.

## Where it is used

Practice 3.

## Source

[`SCD-Concurrency-MPI/src/Practica3/scd-p3-fuentes/filosofos.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica3/scd-p3-fuentes/filosofos.cpp#L1) &mdash; complete file.
