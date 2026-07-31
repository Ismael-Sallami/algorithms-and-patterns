# Dining philosophers, the deadlocking version

## Idea

Every philosopher takes its left fork first. The program is correct in every other respect and still deadlocks, because all four Coffman conditions hold at once. Kept deliberately: it is the counterexample that shows the fix in the previous file is not decoration.

## Cost

Deadlocks with probability approaching one as the run continues.

## Where it is used

Practice 3, teaching counterexample.

## Source

[`concurrency-mpi/src/practice-3-mpi/philosophers-deadlock.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-3-mpi/philosophers-deadlock.cpp#L21-L122) &mdash; complete file.
