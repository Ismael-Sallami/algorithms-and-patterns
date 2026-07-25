# Readers-writers with a monitor and condition variables

## Idea

Many readers may hold the resource at once; a writer must hold it alone. The monitor keeps the reader count and two condition queues, and gives waiting writers priority so that a steady stream of readers cannot starve them. Which side gets priority is a policy decision, not a correctness one.

## Cost

O(1) per entry and exit. Readers proceed in parallel; writers serialise.

## Where it is used

Practice 2, monitors with condition variables.

## Source

[`SCD-Concurrency-MPI/src/Practica2/escritores-lectores.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica2/escritores-lectores.cpp#L1) &mdash; complete file.
