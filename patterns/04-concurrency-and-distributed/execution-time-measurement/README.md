# Measuring worst-case execution time

## Idea

A cyclic executive schedule is only valid if the worst-case execution times it was built from are real. This measures each task repeatedly and keeps the maximum, because the schedule has to survive the worst case, not the average one. The measurement is the input the schedule depends on.

## Cost

n runs per task; the estimate is a lower bound on the true worst case, which is why margin is added.

## Where it is used

Practice 4, feeding the schedule design.

## Source

[`concurrency-mpi/src/practice-4-realtime/timing.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-4-realtime/timing.cpp#L19-L64) &mdash; complete file.
