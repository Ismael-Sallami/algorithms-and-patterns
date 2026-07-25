# Sieve of Eratosthenes as an MPI process pipeline

## Idea

One filter process per prime, chained by message passing. Each filter keeps the first number it receives as its prime, discards later multiples of it, and forwards the rest downstream. No shared memory and no shared sieve array: the algorithm's state is distributed across the pipeline, one prime per process. Termination is a sentinel value flushed through the chain.

## Cost

O(n log log n) total work, spread over as many processes as there are primes below the limit. Latency is proportional to pipeline depth.

## Where it is used

Extra exercise on message-passing decomposition with MPI.

## Source

[`SCD-Concurrency-MPI/src/Extra-MPI-Criba/criba.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Extra-MPI-Criba/criba.cpp#L1) &mdash; complete file.
