# Catalogue

67 implementations across 7 categories. Every row links to the pattern folder and to the file it was extracted from.

## Graph and state-space search

6 patterns.

| Pattern | Language | Extracted from |
| --- | --- | --- |
| [Breadth-first search over a grid state space](patterns/01-graph-search/breadth-first-search/) | C++ | [`Practica2_IA/practica2/rescatador.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/rescatador.cpp) |
| [Dijkstra over a weighted grid with composite state](patterns/01-graph-search/dijkstra-on-a-grid/) | C++ | [`Practica2_IA/practica2/rescatador.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/rescatador.cpp) |
| [A* with a Manhattan-distance heuristic](patterns/01-graph-search/a-star-manhattan/) | C++ | [`Practica2_IA/practica2/rescatador.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/rescatador.cpp) |
| [A* re-targeted at a resupply point when the primary goal is unreachable](patterns/01-graph-search/a-star-with-secondary-objective/) | C++ | [`Practica2_IA/practica2/auxiliar.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/auxiliar.cpp) |
| [Best-first selection of the next cell to explore](patterns/01-graph-search/best-first-frontier-selection/) | C++ | [`Practica2_IA/practica2/rescatador.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/rescatador.cpp) |
| [State transition function and edge cost model](patterns/01-graph-search/state-transition-and-cost-model/) | C++ | [`Practica2_IA/practica2/rescatador.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/rescatador.cpp) |

## Adversarial search

8 patterns.

| Pattern | Language | Extracted from |
| --- | --- | --- |
| [Minimax over a game tree](patterns/02-adversarial-search/minimax/) | C++ | [`Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |
| [Minimax with a hard node budget](patterns/02-adversarial-search/depth-limited-minimax/) | C++ | [`Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |
| [Alpha-beta pruning](patterns/02-adversarial-search/alpha-beta-pruning/) | C++ | [`Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |
| [Alpha-beta with move ordering](patterns/02-adversarial-search/alpha-beta-with-move-ordering/) | C++ | [`Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |
| [Probabilistic cutoff in a chance node tree](patterns/02-adversarial-search/alpha-beta-probabilistic/) | C++ | [`Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |
| [Probabilistic alpha-beta with depth-dependent ordering](patterns/02-adversarial-search/alpha-beta-probabilistic-dynamic-ordering/) | C++ | [`Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |
| [Quiescence search at the horizon](patterns/02-adversarial-search/quiescence-search/) | C++ | [`Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |
| [Evaluation function with weights that follow the game phase](patterns/02-adversarial-search/heuristic-evaluation-and-dynamic-weights/) | C++ | [`Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |

## Metaheuristics and continuous optimisation

16 patterns.

| Pattern | Language | Extracted from |
| --- | --- | --- |
| [Greedy constructive heuristic](patterns/03-metaheuristics/greedy-constructive/) | C++ | [`MH-Practices/practice-3/code/src/greedy.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/greedy.cpp) |
| [Local search, first improvement](patterns/03-metaheuristics/local-search-first-improvement/) | C++ | [`MH-Practices/practice-3/code/src/localsearch.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/localsearch.cpp) |
| [Local search, best improvement](patterns/03-metaheuristics/local-search-best-improvement/) | C++ | [`MH-Practices/practice-3/code/src/localsearch_best.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/localsearch_best.cpp) |
| [Multistart local search](patterns/03-metaheuristics/multistart-local-search/) | C++ | [`MH-Practices/practice-3/code/src/localsearch_multistart.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/localsearch_multistart.cpp) |
| [Basic multistart with a shared best](patterns/03-metaheuristics/basic-multistart-search/) | C++ | [`MH-Practices/practice-3/code/src/bmb.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/bmb.cpp) |
| [Iterated local search](patterns/03-metaheuristics/iterated-local-search/) | C++ | [`MH-Practices/practice-3/code/src/ils.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/ils.cpp) |
| [Iterated local search with simulated annealing as the local optimiser](patterns/03-metaheuristics/iterated-local-search-with-annealing/) | C++ | [`MH-Practices/practice-3/code/src/ils_es.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/ils_es.cpp) |
| [Hybrid of iterated local search, annealing and a CHC population](patterns/03-metaheuristics/hybrid-ils-annealing-chc/) | C++ | [`MH-Practices/practice-3/code/src/ils_es_chc.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/ils_es_chc.cpp) |
| [Simulated annealing](patterns/03-metaheuristics/simulated-annealing/) | C++ | [`MH-Practices/practice-3/code/src/simulated_annealing.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/simulated_annealing.cpp) |
| [Genetic algorithm, generational and steady-state](patterns/03-metaheuristics/genetic-algorithm/) | C++ | [`MH-Practices/practice-3/code/src/genetic_algorithm.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/genetic_algorithm.cpp) |
| [Memetic algorithm](patterns/03-metaheuristics/memetic-algorithm/) | C++ | [`MH-Practices/practice-3/code/src/memetic_algorithm.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/memetic_algorithm.cpp) |
| [Memetic algorithm refining only the best individuals](patterns/03-metaheuristics/memetic-with-selective-refinement/) | C++ | [`MH-Practices/practice-3/code/src/memetic_lsch.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/memetic_lsch.cpp) |
| [Differential evolution](patterns/03-metaheuristics/differential-evolution/) | C++ | [`MH-Practices/practice-3/code/src/differential_evolution.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/differential_evolution.cpp) |
| [Bounded-intensity local search](patterns/03-metaheuristics/soft-local-search/) | C++ | [`MH-Practices/practice-3/code/src/soft_local_search.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/soft_local_search.cpp) |
| [Gaussian mutation with boundary handling](patterns/03-metaheuristics/gaussian-mutation/) | C++ | [`MH-Practices/practice-3/code/src/gaussian_mutation.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/gaussian_mutation.cpp) |
| [Objective function with constraint repair](patterns/03-metaheuristics/objective-function-and-constraint-repair/) | C++ | [`MH-Practices/practice-3/code/src/portfolio_problem.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/portfolio_problem.cpp) |

## Concurrency and distributed systems

12 patterns.

| Pattern | Language | Extracted from |
| --- | --- | --- |
| [Producer-consumer with a FIFO buffer and counting semaphores](patterns/04-concurrency-and-distributed/producer-consumer-fifo-semaphores/) | C++ | [`SCD-Concurrency-MPI/src/Practica1/Primer-Ejercicio/prodcons-plantilla_FIFO.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica1/Primer-Ejercicio/prodcons-plantilla_FIFO.cpp) |
| [Producer-consumer with a LIFO buffer](patterns/04-concurrency-and-distributed/producer-consumer-lifo-semaphores/) | C++ | [`SCD-Concurrency-MPI/src/Practica1/Primer-Ejercicio/prodcons-plantilla_LIFO.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica1/Primer-Ejercicio/prodcons-plantilla_LIFO.cpp) |
| [Several producers and several consumers over one buffer](patterns/04-concurrency-and-distributed/producer-consumer-multiple-semaphores/) | C++ | [`SCD-Concurrency-MPI/src/Practica1/Segundo-Ejercicio/prodcons-multi-FIFO.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica1/Segundo-Ejercicio/prodcons-multi-FIFO.cpp) |
| [Cigarette smokers problem with semaphores](patterns/04-concurrency-and-distributed/cigarette-smokers-semaphores/) | C++ | [`SCD-Concurrency-MPI/src/Practica1/Tercer-Ejercicio/fumadores.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica1/Tercer-Ejercicio/fumadores.cpp) |
| [Readers-writers with a monitor and condition variables](patterns/04-concurrency-and-distributed/readers-writers-monitor/) | C++ | [`SCD-Concurrency-MPI/src/Practica2/escritores-lectores.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica2/escritores-lectores.cpp) |
| [Producer-consumer as a monitor](patterns/04-concurrency-and-distributed/producer-consumer-monitor/) | C++ | [`SCD-Concurrency-MPI/src/Practica2/prodconsMultiple.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica2/prodconsMultiple.cpp) |
| [Signal-and-urgent monitor semantics](patterns/04-concurrency-and-distributed/monitor-signal-and-urgent/) | C++ | [`SCD-Concurrency-MPI/src/Practica3/scd-p3-fuentes/prodcons2-mu.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica3/scd-p3-fuentes/prodcons2-mu.cpp) |
| [Dining philosophers, correct solution](patterns/04-concurrency-and-distributed/dining-philosophers/) | C++ | [`SCD-Concurrency-MPI/src/Practica3/scd-p3-fuentes/filosofos.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica3/scd-p3-fuentes/filosofos.cpp) |
| [Dining philosophers, the deadlocking version](patterns/04-concurrency-and-distributed/dining-philosophers-deadlock/) | C++ | [`SCD-Concurrency-MPI/src/Practica3/scd-p3-fuentes/filosofos-interb.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica3/scd-p3-fuentes/filosofos-interb.cpp) |
| [Dining philosophers with a waiter](patterns/04-concurrency-and-distributed/dining-philosophers-waiter/) | C++ | [`SCD-Concurrency-MPI/src/Practica3/scd-p3-fuentes/filosofos-cam.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica3/scd-p3-fuentes/filosofos-cam.cpp) |
| [Cyclic executive for periodic real-time tasks](patterns/04-concurrency-and-distributed/cyclic-executive-scheduler/) | C++ | [`SCD-Concurrency-MPI/src/Practica4/scd-p4-fuentes/ejecutivo2.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica4/scd-p4-fuentes/ejecutivo2.cpp) |
| [Sieve of Eratosthenes as an MPI process pipeline](patterns/04-concurrency-and-distributed/mpi-pipeline-sieve/) | C++ | [`SCD-Concurrency-MPI/src/Extra-MPI-Criba/criba.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Extra-MPI-Criba/criba.cpp) |

## Data structures and abstract data types

16 patterns.

| Pattern | Language | Extracted from |
| --- | --- | --- |
| [Dynamic two-dimensional matrix with manual memory](patterns/05-data-structures-and-adt/dynamic-2d-matrix/) | C++ | [`TDA-Imagen/ej01_imagenes/estudiante/src/image.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/image.cpp) |
| [Deep copy, assignment and destruction](patterns/05-data-structures-and-adt/deep-copy-and-rule-of-three/) | C++ | [`TDA-Imagen/ej01_imagenes/estudiante/src/image.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/image.cpp) |
| [Single-index access over two-dimensional storage](patterns/05-data-structures-and-adt/linear-indexing-over-2d-storage/) | C++ | [`TDA-Imagen/ej01_imagenes/estudiante/src/image.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/image.cpp) |
| [Contrast adjustment through a lookup table](patterns/05-data-structures-and-adt/lookup-table-transform/) | C++ | [`TDA-Imagen/ej01_imagenes/estudiante/src/imageop.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/imageop.cpp) |
| [Window mean and subsampling](patterns/05-data-structures-and-adt/window-mean-and-subsample/) | C++ | [`TDA-Imagen/ej01_imagenes/estudiante/src/imageop.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/imageop.cpp) |
| [Cropping a submatrix](patterns/05-data-structures-and-adt/submatrix-view/) | C++ | [`TDA-Imagen/ej01_imagenes/estudiante/src/imageop.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/imageop.cpp) |
| [In-place row permutation](patterns/05-data-structures-and-adt/in-place-row-permutation/) | C++ | [`TDA-Imagen/ej01_imagenes/estudiante/src/imageop.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/imageop.cpp) |
| [Zoom by pixel replication and interpolation](patterns/05-data-structures-and-adt/pixel-replication-zoom/) | C++ | [`TDA-Imagen/ej01_imagenes/estudiante/src/imageop.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/imageop.cpp) |
| [Reading and writing a binary PGM file](patterns/05-data-structures-and-adt/binary-format-io/) | C++ | [`TDA-Imagen/ej01_imagenes/estudiante/src/imageIO.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/imageIO.cpp) |
| [Measuring an algorithm's cost empirically](patterns/05-data-structures-and-adt/empirical-complexity-measurement/) | C++ | [`TDA-Imagen/ej05_eficiencia/barajar_puntos_1_5.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej05_eficiencia/barajar_puntos_1_5.cpp) |
| [Hand-written iterator over a 2D container](patterns/05-data-structures-and-adt/custom-forward-iterator/) | C++ | [`Air-lines-Project/rutas_aereas/src/imagen.cpp`](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/src/imagen.cpp) |
| [Compositing one image onto another through a mask](patterns/05-data-structures-and-adt/composition-with-transparency-mask/) | C++ | [`Air-lines-Project/rutas_aereas/src/imagen.cpp`](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/src/imagen.cpp) |
| [Rotating a matrix by an arbitrary angle](patterns/05-data-structures-and-adt/matrix-rotation/) | C++ | [`Air-lines-Project/rutas_aereas/src/pruebarotacion.cpp`](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/src/pruebarotacion.cpp) |
| [Associative store over an ordered map](patterns/05-data-structures-and-adt/ordered-map-backed-store/) | C++ | [`Air-lines-Project/rutas_aereas/src/Almacen_Rutas.cpp`](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/src/Almacen_Rutas.cpp) |
| [Bidirectional iterator with stream serialisation](patterns/05-data-structures-and-adt/bidirectional-iterator-and-stream-operators/) | C++ | [`Air-lines-Project/rutas_aereas/src/Ruta.cpp`](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/src/Ruta.cpp) |
| [Set-backed store with lookup by two different keys](patterns/05-data-structures-and-adt/set-backed-store-with-multiple-lookups/) | C++ | [`Air-lines-Project/rutas_aereas/src/Paises.cpp`](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/src/Paises.cpp) |

## Applied machine learning

5 patterns.

| Pattern | Language | Extracted from |
| --- | --- | --- |
| [Comparing classifiers under cross-validation](patterns/06-applied-machine-learning/model-selection-with-cross-validation/) | Python | [`AA-practices/practice-1/P1_Ismael_Sallami_Moreno.ipynb`](https://github.com/Ismael-Sallami/AA-practices/blob/main/practice-1/P1_Ismael_Sallami_Moreno.ipynb) |
| [Choosing the DBSCAN neighbourhood radius from data](patterns/06-applied-machine-learning/dbscan-epsilon-selection/) | Python | [`AA-practices/practice-2/P2_Sallami_Moreno_Ismael.ipynb`](https://github.com/Ismael-Sallami/AA-practices/blob/main/practice-2/P2_Sallami_Moreno_Ismael.ipynb) |
| [Choosing the number of clusters](patterns/06-applied-machine-learning/cluster-count-selection/) | Python | [`AA-practices/practice-2/P2_Sallami_Moreno_Ismael.ipynb`](https://github.com/Ismael-Sallami/AA-practices/blob/main/practice-2/P2_Sallami_Moreno_Ismael.ipynb) |
| [One-hot sequence encoding and network regularisation](patterns/06-applied-machine-learning/sequence-vectorisation-and-regularisation/) | Python | [`AA-practices/practice-3/P3_SALLAMI_MORENO_ISMAEL.ipynb`](https://github.com/Ismael-Sallami/AA-practices/blob/main/practice-3/P3_SALLAMI_MORENO_ISMAEL.ipynb) |
| [Greedy decoding of a sequence-to-sequence model](patterns/06-applied-machine-learning/seq2seq-greedy-decoding/) | Python | [`AA-practices/project/Proyecto_Sallami_Rodriguez.ipynb`](https://github.com/Ismael-Sallami/AA-practices/blob/main/project/Proyecto_Sallami_Rodriguez.ipynb) |

## Databases and transactions

4 patterns.

| Pattern | Language | Extracted from |
| --- | --- | --- |
| [Relational schema with declarative constraints](patterns/07-databases-and-transactions/relational-schema-and-constraints/) | SQL | [`DDSI/LaTeX/pr3/database/00_init_tablas.sql`](https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/database/00_init_tablas.sql) |
| [Business rules enforced by triggers](patterns/07-databases-and-transactions/trigger-based-integrity/) | SQL | [`DDSI/LaTeX/pr3/database/publicidad/triggers_publicidad.sql`](https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/database/publicidad/triggers_publicidad.sql) |
| [Server-side procedures](patterns/07-databases-and-transactions/stored-procedures/) | SQL | [`DDSI/LaTeX/pr3/database/publicidad/procedures_publicidad.sql`](https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/database/publicidad/procedures_publicidad.sql) |
| [Multi-statement writes with commit and rollback](patterns/07-databases-and-transactions/transactional-write-path/) | Python | [`DDSI/LaTeX/pr3/src/usuarios/functions.py`](https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/src/usuarios/functions.py) |

## Author

Ismael Sallami Moreno
