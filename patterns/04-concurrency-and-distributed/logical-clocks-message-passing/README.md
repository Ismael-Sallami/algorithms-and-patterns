# Logical clocks over message passing

## Idea

Distributed processes have no shared clock, so ordering events by wall time is not available. A counter carried in every message and advanced on receipt gives a consistent ordering of causally related events. It cannot order concurrent ones, and it is not meant to.

## Cost

O(1) per message. One integer of state per process.

## Where it is used

Practice 4, distributed synchronisation with MPI.

## Source

[`concurrency-mpi/src/practice-4-realtime/clocks.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-4-realtime/clocks.cpp#L19-L53) &mdash; complete file.
