# Cigarette smokers problem with semaphores

## Idea

One agent supplies one of three ingredients at random; each smoker waits for exactly the one it lacks. Solved with one semaphore per ingredient, which turns 'wake the right thread' into a signal on the right semaphore instead of a broadcast plus a re-check. The problem exists to show that condition-per-waiter beats wake-all.

## Cost

O(1) per cigarette. Exactly one thread wakes per signal.

## Where it is used

Practice 1, third exercise.

## Source

[`concurrency-mpi/src/practice-1-semaphores/smokers/smokers.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-1-semaphores/smokers/smokers.cpp#L9-L126) &mdash; complete file.
