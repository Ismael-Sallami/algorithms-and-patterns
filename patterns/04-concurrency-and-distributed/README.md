# Concurrency and distributed systems

Classic synchronisation problems solved twice over: once with counting semaphores and once with monitors and condition variables. Closes with a real-time cyclic executive and a message-passing pipeline in MPI.

12 patterns.

| Pattern | Language | Source |
| --- | --- | --- |
| [Producer-consumer with a FIFO buffer and counting semaphores](producer-consumer-fifo-semaphores/) | C++ | [`concurrency-mpi`](https://github.com/Ismael-Sallami/concurrency-mpi) |
| [Producer-consumer with a LIFO buffer](producer-consumer-lifo-semaphores/) | C++ | [`concurrency-mpi`](https://github.com/Ismael-Sallami/concurrency-mpi) |
| [Several producers and several consumers over one buffer](producer-consumer-multiple-semaphores/) | C++ | [`concurrency-mpi`](https://github.com/Ismael-Sallami/concurrency-mpi) |
| [Cigarette smokers problem with semaphores](cigarette-smokers-semaphores/) | C++ | [`concurrency-mpi`](https://github.com/Ismael-Sallami/concurrency-mpi) |
| [Readers-writers with a monitor and condition variables](readers-writers-monitor/) | C++ | [`concurrency-mpi`](https://github.com/Ismael-Sallami/concurrency-mpi) |
| [Producer-consumer as a monitor](producer-consumer-monitor/) | C++ | [`concurrency-mpi`](https://github.com/Ismael-Sallami/concurrency-mpi) |
| [Signal-and-urgent monitor semantics](monitor-signal-and-urgent/) | C++ | [`concurrency-mpi`](https://github.com/Ismael-Sallami/concurrency-mpi) |
| [Dining philosophers, correct solution](dining-philosophers/) | C++ | [`concurrency-mpi`](https://github.com/Ismael-Sallami/concurrency-mpi) |
| [Dining philosophers, the deadlocking version](dining-philosophers-deadlock/) | C++ | [`concurrency-mpi`](https://github.com/Ismael-Sallami/concurrency-mpi) |
| [Dining philosophers with a waiter](dining-philosophers-waiter/) | C++ | [`concurrency-mpi`](https://github.com/Ismael-Sallami/concurrency-mpi) |
| [Cyclic executive for periodic real-time tasks](cyclic-executive-scheduler/) | C++ | [`concurrency-mpi`](https://github.com/Ismael-Sallami/concurrency-mpi) |
| [Sieve of Eratosthenes as an MPI process pipeline](mpi-pipeline-sieve/) | C++ | [`concurrency-mpi`](https://github.com/Ismael-Sallami/concurrency-mpi) |

[Back to the catalogue](../../README.md)
