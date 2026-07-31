# Producer-consumer as a monitor

## Idea

The bounded buffer again, this time with the state and the operations encapsulated in a monitor. The difference from the semaphore version is structural: mutual exclusion is implicit in monitor entry, and waiting is expressed as a condition on the state rather than as a count. Bugs of the 'forgot to signal' kind become visible in one place.

## Cost

O(1) per item. One thread inside the monitor at a time.

## Where it is used

Practice 2.

## Source

[`concurrency-mpi/src/practice-2-monitors/producer-consumer-multi.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-2-monitors/producer-consumer-multi.cpp#L26-L260) &mdash; complete file.
