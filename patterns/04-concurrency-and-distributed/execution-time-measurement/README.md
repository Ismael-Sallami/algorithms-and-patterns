# Measuring worst-case execution time

## Idea

A cyclic executive schedule is only valid if the worst-case execution times it was built from are real. This measures each task repeatedly and keeps the maximum, because the schedule has to survive the worst case, not the average one. The measurement is the input the schedule depends on.

## Cost

n runs per task; the estimate is a lower bound on the true worst case, which is why margin is added.

## Where it is used

Practice 4, feeding the schedule design.

## Source

[`SCD-Concurrency-MPI/src/Practica4/scd-p4-fuentes/tiempos.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica4/scd-p4-fuentes/tiempos.cpp#L1) &mdash; complete file.
