# Cyclic executive with a compressed frame schedule

## Idea

The same periodic task set on a shorter frame. Halving the frame lets a task with a tighter deadline be scheduled, at the cost of splitting longer tasks across frames. That trade - frame length against schedulability - is the whole design space of a cyclic executive.

## Cost

Frame length must divide the hyperperiod and bound the worst-case execution time of the tasks placed in it.

## Where it is used

Practice 4, real-time scheduling.

## Source

[`SCD-Concurrency-MPI/src/Practica4/scd-p4-fuentes/ejecutivo1-compr.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica4/scd-p4-fuentes/ejecutivo1-compr.cpp#L1) &mdash; complete file.
