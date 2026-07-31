# Signal-and-urgent monitor semantics

## Idea

Under signal-and-urgent the signalling thread yields the monitor to the woken thread immediately, so the condition it just established still holds when the waiter resumes. Under signal-and-continue the waiter has to re-check, because the signaller keeps running. The same program written for the wrong semantics is a race, which is why the distinction is worth an implementation of its own.

## Cost

O(1) per operation. Saves the re-check loop that signal-and-continue needs.

## Where it is used

Practice 3, contrasted against the signal-and-continue version in the same directory.

## Source

[`concurrency-mpi/src/practice-3-mpi/producer-consumer-multi.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-3-mpi/producer-consumer-multi.cpp#L22-L207) &mdash; complete file.
