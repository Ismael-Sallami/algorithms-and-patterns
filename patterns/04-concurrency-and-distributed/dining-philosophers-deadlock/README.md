# Dining philosophers, the deadlocking version

## Idea

Every philosopher takes its left fork first. The program is correct in every other respect and still deadlocks, because all four Coffman conditions hold at once. Kept deliberately: it is the counterexample that shows the fix in the previous file is not decoration.

## Cost

Deadlocks with probability approaching one as the run continues.

## Where it is used

Practice 3, teaching counterexample.

## Source

[`SCD-Concurrency-MPI/src/Practica3/scd-p3-fuentes/filosofos-interb.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica3/scd-p3-fuentes/filosofos-interb.cpp#L1) &mdash; complete file.
