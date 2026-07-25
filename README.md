# Algorithms and Patterns

A catalogue of algorithms and data structures I implemented during the double
degree in Computer Science and Business Administration at the University of
Granada, reorganised by pattern rather than by subject.

The code here is not written for this repository. Each folder holds the original
implementation, sliced out of the repository it was written in, with a header
naming the source file and the line range it came from. Every extract links back
to the repository that holds its commit history, so any claim made here can be
checked against the work it came from.

## Counters

| Category | Implementations |
| --- | ---: |
| [Graph and state-space search](patterns/01-graph-search/) | 6 |
| [Adversarial search](patterns/02-adversarial-search/) | 8 |
| [Metaheuristics and continuous optimisation](patterns/03-metaheuristics/) | 16 |
| [Concurrency and distributed systems](patterns/04-concurrency-and-distributed/) | 12 |
| [Data structures and abstract data types](patterns/05-data-structures-and-adt/) | 16 |
| [Applied machine learning](patterns/06-applied-machine-learning/) | 5 |
| [Databases and transactions](patterns/07-databases-and-transactions/) | 4 |
| **Total** | **67** |

Solutions to problems on judge platforms are kept separately, in
[`neetcode-submissions`](https://github.com/Ismael-Sallami/neetcode-submissions):
5 problems. The two figures are reported apart because they
measure different things - coursework implementations on one side, platform
exercises on the other.

Run `python3 scripts/count_patterns.py` to regenerate the table above from the
directory tree.

## How to read this repository

1. **The code is copied, not rewritten.** Extracts are verbatim. The only
   removals are file-level includes and surrounding context that belongs to the
   original build.
2. **Only my own code is here.** Where a subject supplied a framework - the
   Parchis engine, the simulation engine, the metaheuristics base classes - that
   framework is referenced but never copied. What is catalogued is the part I
   wrote.
3. **Extracts are not standalone builds.** Each one names its origin so it can
   be read in context. Clone the source repository to compile or run it.
4. **Category 06 is applied work.** The models come from scikit-learn and Keras.
   What is catalogued there is the pipeline, the parameter search and the
   evaluation logic, and each folder says so.

## Catalogue

[`CATALOG.md`](CATALOG.md) lists every pattern with its language and its origin
in one table. Or browse by category:

- [Graph and state-space search](patterns/01-graph-search/) &mdash; 6 patterns
- [Adversarial search](patterns/02-adversarial-search/) &mdash; 8 patterns
- [Metaheuristics and continuous optimisation](patterns/03-metaheuristics/) &mdash; 16 patterns
- [Concurrency and distributed systems](patterns/04-concurrency-and-distributed/) &mdash; 12 patterns
- [Data structures and abstract data types](patterns/05-data-structures-and-adt/) &mdash; 16 patterns
- [Applied machine learning](patterns/06-applied-machine-learning/) &mdash; 5 patterns
- [Databases and transactions](patterns/07-databases-and-transactions/) &mdash; 4 patterns

## Source repositories

| Repository | Content |
| --- | --- |
| [`Parcherckers`](https://github.com/Ismael-Sallami/Parcherckers) | Adversarial search agent for Parchis, a four-player board game with dice. Artificial Intelligence, 3rd year. |
| [`Practica2_IA`](https://github.com/Ismael-Sallami/Practica2_IA) | Reactive and deliberative agents planning over a partially known map. Artificial Intelligence, 3rd year. |
| [`MH-Practices`](https://github.com/Ismael-Sallami/MH-Practices) | Sixteen metaheuristics applied to a portfolio allocation problem. Metaheuristics, 4th year. |
| [`SCD-Concurrency-MPI`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI) | Classic synchronisation problems with semaphores, monitors and MPI. Concurrent and Distributed Systems, 2nd year. |
| [`TDA-Imagen`](https://github.com/Ismael-Sallami/TDA-Imagen) | Image abstract data type with manual memory management. Data Structures, 2nd year. |
| [`Air-lines-Project`](https://github.com/Ismael-Sallami/Air-lines-Project) | Air route system with custom containers and iterators. Data Structures, 2nd year. |
| [`AA-practices`](https://github.com/Ismael-Sallami/AA-practices) | Supervised learning, clustering and neural networks. Machine Learning, 4th year. |
| [`DDSI`](https://github.com/Ismael-Sallami/DDSI) | Relational schema, triggers, procedures and transactional write paths. Database Design, 3rd year. |

## Related

- [`neetcode-submissions`](https://github.com/Ismael-Sallami/neetcode-submissions) &mdash;
  solutions to NeetCode problems, synchronised from the platform.
- [`3-Partition-NP-Completeness`](https://github.com/Ismael-Sallami/3-Partition-NP-Completeness)
  &mdash; write-up of the reduction proving 3-Partition is NP-complete. Proof
  only, no implementation, which is why it has no folder here.

## Licence

MIT. See [`LICENSE`](LICENSE).

Where a source repository was joint coursework, the extracts in this repository
are limited to the parts I wrote. Co-authors are credited in the source
repositories.

## Author

Ismael Sallami Moreno
