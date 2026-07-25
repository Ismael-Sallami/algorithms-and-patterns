# Cigarette smokers problem with semaphores

## Idea

One agent supplies one of three ingredients at random; each smoker waits for exactly the one it lacks. Solved with one semaphore per ingredient, which turns 'wake the right thread' into a signal on the right semaphore instead of a broadcast plus a re-check. The problem exists to show that condition-per-waiter beats wake-all.

## Cost

O(1) per cigarette. Exactly one thread wakes per signal.

## Where it is used

Practice 1, third exercise.

## Source

[`SCD-Concurrency-MPI/src/Practica1/Tercer-Ejercicio/fumadores.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica1/Tercer-Ejercicio/fumadores.cpp#L1) &mdash; complete file.
