# Cyclic executive with a compressed frame schedule

## Idea

The same periodic task set on a shorter frame. Halving the frame lets a task with a tighter deadline be scheduled, at the cost of splitting longer tasks across frames. That trade - frame length against schedulability - is the whole design space of a cyclic executive.

## Cost

Frame length must divide the hyperperiod and bound the worst-case execution time of the tasks placed in it.

## Where it is used

Practice 4, real-time scheduling.

## Source

[`concurrency-mpi/src/practice-4-realtime/cyclic-executive-1-checked.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-4-realtime/cyclic-executive-1-checked.cpp#L7-L76) &mdash; complete file.
