# Concurrency and distributed systems

Classic synchronisation problems solved twice over: once with counting semaphores and once with monitors and condition variables. Closes with a real-time cyclic executive and a message-passing pipeline in MPI.

12 patterns.

| Pattern | Language | Source |
| --- | --- | --- |
| [Producer-consumer with a FIFO buffer and counting semaphores](producer-consumer-fifo-semaphores/) | C++ | [`SCD-Concurrency-MPI`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI) |
| [Producer-consumer with a LIFO buffer](producer-consumer-lifo-semaphores/) | C++ | [`SCD-Concurrency-MPI`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI) |
| [Several producers and several consumers over one buffer](producer-consumer-multiple-semaphores/) | C++ | [`SCD-Concurrency-MPI`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI) |
| [Cigarette smokers problem with semaphores](cigarette-smokers-semaphores/) | C++ | [`SCD-Concurrency-MPI`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI) |
| [Readers-writers with a monitor and condition variables](readers-writers-monitor/) | C++ | [`SCD-Concurrency-MPI`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI) |
| [Producer-consumer as a monitor](producer-consumer-monitor/) | C++ | [`SCD-Concurrency-MPI`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI) |
| [Signal-and-urgent monitor semantics](monitor-signal-and-urgent/) | C++ | [`SCD-Concurrency-MPI`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI) |
| [Dining philosophers, correct solution](dining-philosophers/) | C++ | [`SCD-Concurrency-MPI`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI) |
| [Dining philosophers, the deadlocking version](dining-philosophers-deadlock/) | C++ | [`SCD-Concurrency-MPI`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI) |
| [Dining philosophers with a waiter](dining-philosophers-waiter/) | C++ | [`SCD-Concurrency-MPI`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI) |
| [Cyclic executive for periodic real-time tasks](cyclic-executive-scheduler/) | C++ | [`SCD-Concurrency-MPI`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI) |
| [Sieve of Eratosthenes as an MPI process pipeline](mpi-pipeline-sieve/) | C++ | [`SCD-Concurrency-MPI`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI) |

[Back to the catalogue](../../README.md)
