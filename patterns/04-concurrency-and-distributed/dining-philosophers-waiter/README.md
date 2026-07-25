# Dining philosophers with a waiter

## Idea

A separate waiter process admits at most four philosophers to the table. With one seat always free the circular wait cannot close, so deadlock is impossible without asymmetric fork ordering. A different fix for the same problem: bound the resource demand instead of breaking the cycle.

## Cost

O(1) per meal, with the waiter as an extra serialisation point.

## Where it is used

Practice 3.

## Source

[`SCD-Concurrency-MPI/src/Practica3/scd-p3-fuentes/filosofos-cam.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica3/scd-p3-fuentes/filosofos-cam.cpp#L1) &mdash; complete file.
