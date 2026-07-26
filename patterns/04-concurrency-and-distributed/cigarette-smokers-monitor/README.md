# Cigarette smokers problem with a monitor

## Idea

The same problem as the semaphore version, expressed as a monitor with one condition variable per smoker. Comparing the two is the point of solving it twice: the semaphore version encodes who to wake in which semaphore is signalled, the monitor version in which condition is signalled, and the monitor makes the invariant readable in one place.

## Cost

O(1) per cigarette. One thread inside the monitor at a time.

## Where it is used

Practice 2, monitors.

## Source

[`SCD-Concurrency-MPI/src/Practica2/fumadores.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica2/fumadores.cpp#L1) &mdash; complete file.
