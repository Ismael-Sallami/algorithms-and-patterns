# Cyclic executive for periodic real-time tasks

## Idea

Static scheduling of periodic tasks: the hyperperiod is the least common multiple of the task periods, divided into frames, and each frame runs a fixed sequence. There is no run-time scheduler and no preemption, so timing is verifiable by hand - but a task that overruns its frame breaks the schedule with nothing to catch it.

## Cost

Hyperperiod = lcm of periods. Frame length must divide it and must be long enough for the worst-case execution time of its tasks.

## Where it is used

Practice 4, real-time scheduling.

## Source

[`SCD-Concurrency-MPI/src/Practica4/scd-p4-fuentes/ejecutivo2.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica4/scd-p4-fuentes/ejecutivo2.cpp#L1) &mdash; complete file.
