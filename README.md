# Algorithms and Patterns

![C++](https://img.shields.io/badge/C%2B%2B-20-00599C)
[![tests](https://img.shields.io/github/actions/workflow/status/Ismael-Sallami/algorithms-and-patterns/ci.yml?branch=main&logo=github&label=tests)](https://github.com/Ismael-Sallami/algorithms-and-patterns/actions/workflows/ci.yml)
![license](https://img.shields.io/badge/license-MIT-4c1)

A catalogue of 183 algorithm and data structure implementations, organised by
pattern. It has two halves, kept apart on purpose.

**[`patterns/`](patterns/) &mdash; 126 extracts from earlier work.** Code I
wrote during the double degree in Computer Science and Business Administration at the
University of Granada, and in my own projects since, reorganised by pattern rather than by
subject. Nothing here was written for this repository: each file is the original
implementation, sliced out of the repository it belongs to, with a header naming the source
file and line range and a link to it. Every claim is checkable against the commit history
that produced it.

**[`reference/`](reference/) &mdash; 57 implementations written for this
repository.** Canonical algorithms that my coursework never produced a committed
implementation of, covering the standard interview taxonomy and the computer architecture
mechanisms I studied without writing code for. These have no prior commit history and their
headers say so. Each one is self-contained and asserts its own behaviour, so it is verified
by compiling and running it.

## Verifying it

The CI compiles and runs the 57 reference implementations on every push. They print
nothing and assert their own behaviour, so a silent run is a pass and a broken invariant
aborts the build:

```bash
bash scripts/verify.sh
```

```
ok    reference/01-arrays-and-hashing/in-place-matrix-transforms/in_place_matrix_transforms.cpp
...
57 reference implementations compile and verify themselves
```

The files under `patterns/` are not compiled: they are fragments of larger programs, kept
with a link to the commit they came from, and they do not stand alone. What can be checked
about them is their provenance, and every header carries it.

## Counters

### Extracted from earlier work

| Category | Implementations |
| --- | ---: |
| [Graph and state-space search](patterns/01-graph-search/) | 13 |
| [Adversarial search](patterns/02-adversarial-search/) | 15 |
| [Metaheuristics and continuous optimisation](patterns/03-metaheuristics/) | 22 |
| [Concurrency and distributed systems](patterns/04-concurrency-and-distributed/) | 19 |
| [Data structures and abstract data types](patterns/05-data-structures-and-adt/) | 23 |
| [Applied machine learning](patterns/06-applied-machine-learning/) | 5 |
| [Databases and transactions](patterns/07-databases-and-transactions/) | 11 |
| [Application architecture](patterns/08-application-architecture/) | 18 |

### Written for this repository

| Category | Implementations |
| --- | ---: |
| [Arrays and hashing](reference/01-arrays-and-hashing/) | 5 |
| [Two pointers and sliding window](reference/02-two-pointers-and-sliding-window/) | 5 |
| [Stacks and monotonic structures](reference/03-stack-and-monotonic-structures/) | 1 |
| [Binary search](reference/04-binary-search/) | 1 |
| [Linked lists](reference/05-linked-lists/) | 2 |
| [Trees and tries](reference/06-trees-and-tries/) | 6 |
| [Heaps and priority queues](reference/07-heaps-and-priority-queues/) | 2 |
| [Backtracking](reference/08-backtracking/) | 1 |
| [Graphs](reference/09-graphs/) | 7 |
| [Advanced graphs](reference/10-advanced-graphs/) | 7 |
| [Dynamic programming](reference/11-dynamic-programming/) | 3 |
| [Greedy algorithms and intervals](reference/12-greedy-and-intervals/) | 2 |
| [String algorithms](reference/13-string-algorithms/) | 2 |
| [Mathematics and bit manipulation](reference/14-math-and-bit-manipulation/) | 2 |
| [Computer architecture](reference/15-computer-architecture/) | 9 |
| [Systems primitives](reference/16-systems-primitives/) | 2 |

**Total: 183 implementations** &mdash; 126 extracted, 57 written here.

Problems solved on NeetCode are tracked separately, in [`neetcode-submissions`](https://github.com/Ismael-Sallami/neetcode-submissions): 5 at the last count.

Run `python3 scripts/count.py` to regenerate these tables from the directory tree.

## How to read this repository

1. **Under `patterns/`, the code is copied, not rewritten.** Extracts are verbatim. The only
   removals are file-level includes and surrounding context belonging to the original build.
   They are not standalone builds; each names its origin so it can be read in context.
2. **Only my own code is extracted.** Where a subject supplied a framework &mdash; the
   Parchis engine, the simulation engine, the metaheuristics base classes &mdash; that
   framework is referenced and never copied. What is catalogued is the part I wrote.
3. **Under `reference/`, the code was written here and says so.** No provenance link is
   claimed for it, because there is none. Every file compiles with `g++ -std=c++20` and
   exits zero, which is what its assertions check.
4. **Applied work is labelled as applied.** The machine learning folders call scikit-learn
   and Keras; what is catalogued is the pipeline, the parameter search and the evaluation
   logic, and each folder says so.

## Catalogue

[`CATALOG.md`](CATALOG.md) lists every entry in one table, with its language and its origin.
Or browse by category.

Extracted from earlier work:

- [Graph and state-space search](patterns/01-graph-search/) &mdash; 13
- [Adversarial search](patterns/02-adversarial-search/) &mdash; 15
- [Metaheuristics and continuous optimisation](patterns/03-metaheuristics/) &mdash; 22
- [Concurrency and distributed systems](patterns/04-concurrency-and-distributed/) &mdash; 19
- [Data structures and abstract data types](patterns/05-data-structures-and-adt/) &mdash; 23
- [Applied machine learning](patterns/06-applied-machine-learning/) &mdash; 5
- [Databases and transactions](patterns/07-databases-and-transactions/) &mdash; 11
- [Application architecture](patterns/08-application-architecture/) &mdash; 18

Written for this repository:

- [Arrays and hashing](reference/01-arrays-and-hashing/) &mdash; 5
- [Two pointers and sliding window](reference/02-two-pointers-and-sliding-window/) &mdash; 5
- [Stacks and monotonic structures](reference/03-stack-and-monotonic-structures/) &mdash; 1
- [Binary search](reference/04-binary-search/) &mdash; 1
- [Linked lists](reference/05-linked-lists/) &mdash; 2
- [Trees and tries](reference/06-trees-and-tries/) &mdash; 6
- [Heaps and priority queues](reference/07-heaps-and-priority-queues/) &mdash; 2
- [Backtracking](reference/08-backtracking/) &mdash; 1
- [Graphs](reference/09-graphs/) &mdash; 7
- [Advanced graphs](reference/10-advanced-graphs/) &mdash; 7
- [Dynamic programming](reference/11-dynamic-programming/) &mdash; 3
- [Greedy algorithms and intervals](reference/12-greedy-and-intervals/) &mdash; 2
- [String algorithms](reference/13-string-algorithms/) &mdash; 2
- [Mathematics and bit manipulation](reference/14-math-and-bit-manipulation/) &mdash; 2
- [Computer architecture](reference/15-computer-architecture/) &mdash; 9
- [Systems primitives](reference/16-systems-primitives/) &mdash; 2

## Source repositories

Every extract under `patterns/` comes from one of these.

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
| [`personal-finance-manager`](https://github.com/Ismael-Sallami/personal-finance-manager) | Self-hosted finance service: broker statement parsing, money arithmetic, background jobs. Personal project. |
| [`media-manager`](https://github.com/Ismael-Sallami/media-manager) | Photo transfer and deduplication by content hash. Personal project. |
| [`md2html-testGenerator`](https://github.com/Ismael-Sallami/md2html-testGenerator) | Markdown to interactive HTML converter. Personal project. |
| [`pdf-to-md`](https://github.com/Ismael-Sallami/pdf-to-md) | PDF to Markdown converter with layered extraction fallbacks. Personal project. |
| [`ModeloEconometrico`](https://github.com/Ismael-Sallami/ModeloEconometrico) | Linear regression with assumption diagnostics. Econometrics coursework. |

## Related

- [`neetcode-submissions`](https://github.com/Ismael-Sallami/neetcode-submissions) &mdash; solutions to
  NeetCode problems, synchronised from the platform.
- [`3-Partition-NP-Completeness`](https://github.com/Ismael-Sallami/3-Partition-NP-Completeness)
  &mdash; write-up of the reduction proving 3-Partition is NP-complete. Proof only, no
  implementation, which is why it has no folder here.

## Licence

MIT. See [`LICENSE`](LICENSE).

Where a source repository was joint coursework, the extracts here are limited to the parts I
wrote. Co-authors are credited in the source repositories.

## Author

Ismael Sallami Moreno
