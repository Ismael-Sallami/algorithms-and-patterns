# Catalogue

198 implementations: 141 extracted from earlier work and 57 written for this repository.

## Extracted from earlier work

Each row links to the folder and to the file it was sliced out of.

### Graph and state-space search

13 entries.

| Entry | Language | Extracted from |
| --- | --- | --- |
| [A* with a Manhattan-distance heuristic](patterns/01-graph-search/a-star-manhattan/) | C++ | [`Ismael-Sallami/Practica2_IA/practica2/rescatador.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/rescatador.cpp) |
| [A* re-targeted at a resupply point when the primary goal is unreachable](patterns/01-graph-search/a-star-with-secondary-objective/) | C++ | [`Ismael-Sallami/Practica2_IA/practica2/auxiliar.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/auxiliar.cpp) |
| [Best-first selection of the next cell to explore](patterns/01-graph-search/best-first-frontier-selection/) | C++ | [`Ismael-Sallami/Practica2_IA/practica2/rescatador.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/rescatador.cpp) |
| [Breadth-first search over a grid state space](patterns/01-graph-search/breadth-first-search/) | C++ | [`Ismael-Sallami/Practica2_IA/practica2/rescatador.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/rescatador.cpp) |
| [Dijkstra over a weighted grid with composite state](patterns/01-graph-search/dijkstra-on-a-grid/) | C++ | [`Ismael-Sallami/Practica2_IA/practica2/rescatador.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/rescatador.cpp) |
| [Scoring frontier cells by surrounding unknown area](patterns/01-graph-search/frontier-scoring-by-unknown-neighbours/) | C++ | [`Ismael-Sallami/Practica2_IA/practica2/auxiliar.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/auxiliar.cpp) |
| [Reactive agent driven by a target predicate](patterns/01-graph-search/goal-directed-reactive-agent/) | C++ | [`Ismael-Sallami/Practica2_IA/IA_Practica2/Comportamientos_Jugador/vandalo.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/IA_Practica2/Comportamientos_Jugador/vandalo.cpp) |
| [Layered reactive control without a plan](patterns/01-graph-search/layered-reactive-control/) | C++ | [`Ismael-Sallami/Practica2_IA/practica2/rescatador.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/rescatador.cpp) |
| [Minimal reactive agent](patterns/01-graph-search/minimal-reactive-agent/) | C++ | [`Ismael-Sallami/Practica2_IA/IA_Practica2/Comportamientos_Jugador/excursionista.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/IA_Practica2/Comportamientos_Jugador/excursionista.cpp) |
| [Legal move generation with collision avoidance](patterns/01-graph-search/move-generation-with-collision-avoidance/) | C++ | [`Ismael-Sallami/Practica2_IA/practica2/rescatador.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/rescatador.cpp) |
| [Breaking movement loops with visit counters](patterns/01-graph-search/revisit-counting-to-break-loops/) | C++ | [`Ismael-Sallami/Practica2_IA/practica2/rescatador.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/rescatador.cpp) |
| [Projecting a local sensor reading onto a global map](patterns/01-graph-search/sensor-to-map-projection/) | C++ | [`Ismael-Sallami/Practica2_IA/practica2/auxiliar.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/auxiliar.cpp) |
| [State transition function and edge cost model](patterns/01-graph-search/state-transition-and-cost-model/) | C++ | [`Ismael-Sallami/Practica2_IA/practica2/rescatador.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/rescatador.cpp) |

### Adversarial search

15 entries.

| Entry | Language | Extracted from |
| --- | --- | --- |
| [Probabilistic cutoff in a chance node tree](patterns/02-adversarial-search/alpha-beta-probabilistic/) | C++ | [`Ismael-Sallami/Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |
| [Probabilistic alpha-beta with depth-dependent ordering](patterns/02-adversarial-search/alpha-beta-probabilistic-dynamic-ordering/) | C++ | [`Ismael-Sallami/Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |
| [Alpha-beta pruning](patterns/02-adversarial-search/alpha-beta-pruning/) | C++ | [`Ismael-Sallami/Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |
| [Alpha-beta with move ordering](patterns/02-adversarial-search/alpha-beta-with-move-ordering/) | C++ | [`Ismael-Sallami/Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |
| [Alpha-beta with tuned cutoff conditions](patterns/02-adversarial-search/alpha-beta-with-tuned-cutoffs/) | C++ | [`Ismael-Sallami/Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |
| [Minimax with a hard node budget](patterns/02-adversarial-search/depth-limited-minimax/) | C++ | [`Ismael-Sallami/Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |
| [Baseline evaluation function](patterns/02-adversarial-search/evaluation-baseline/) | C++ | [`Ismael-Sallami/Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |
| [Evaluation whose weights follow the game phase](patterns/02-adversarial-search/evaluation-with-dynamic-weights/) | C++ | [`Ismael-Sallami/Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |
| [Evaluation with positional zones and distance bands](patterns/02-adversarial-search/evaluation-with-positional-zones/) | C++ | [`Ismael-Sallami/Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |
| [Evaluation with piece safety and capture terms](patterns/02-adversarial-search/evaluation-with-safety-terms/) | C++ | [`Ismael-Sallami/Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |
| [Weighted linear evaluation over hand-picked features](patterns/02-adversarial-search/evaluation-with-weighted-features/) | C++ | [`Ismael-Sallami/Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |
| [Greedy and random move policies](patterns/02-adversarial-search/greedy-move-policies/) | C++ | [`Ismael-Sallami/Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |
| [Evaluation function with weights that follow the game phase](patterns/02-adversarial-search/heuristic-evaluation-and-dynamic-weights/) | C++ | [`Ismael-Sallami/Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |
| [Minimax over a game tree](patterns/02-adversarial-search/minimax/) | C++ | [`Ismael-Sallami/Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |
| [Quiescence search at the horizon](patterns/02-adversarial-search/quiescence-search/) | C++ | [`Ismael-Sallami/Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp) |

### Metaheuristics and continuous optimisation

22 entries.

| Entry | Language | Extracted from |
| --- | --- | --- |
| [Unit tests for the optimisation components](patterns/03-metaheuristics/algorithm-unit-tests/) | C++ | [`Ismael-Sallami/MH-Practices/practice-1/tests/test.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-1/tests/test.cpp) |
| [Basic multistart with a shared best](patterns/03-metaheuristics/basic-multistart-search/) | C++ | [`Ismael-Sallami/MH-Practices/practice-3/code/src/bmb.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/bmb.cpp) |
| [Convergence curves and boxplot comparison](patterns/03-metaheuristics/convergence-curves/) | Python | [`Ismael-Sallami/MH-Practices/practice-3/EXTRA/convergencia_comparativa.py`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/EXTRA/convergencia_comparativa.py) |
| [Parsing delimited numeric series](patterns/03-metaheuristics/delimited-data-parsing/) | C++ | [`Ismael-Sallami/MH-Practices/practice-3/code/src/csv_reader.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/csv_reader.cpp) |
| [Differential evolution](patterns/03-metaheuristics/differential-evolution/) | C++ | [`Ismael-Sallami/MH-Practices/practice-3/code/src/differential_evolution.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/differential_evolution.cpp) |
| [Repeated-run protocol with mean and standard deviation](patterns/03-metaheuristics/experimental-protocol/) | C++ | [`Ismael-Sallami/MH-Practices/practice-3/code/main.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/main.cpp) |
| [Gaussian mutation with boundary handling](patterns/03-metaheuristics/gaussian-mutation/) | C++ | [`Ismael-Sallami/MH-Practices/practice-3/code/src/gaussian_mutation.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/gaussian_mutation.cpp) |
| [Genetic algorithm, generational and steady-state](patterns/03-metaheuristics/genetic-algorithm/) | C++ | [`Ismael-Sallami/MH-Practices/practice-3/code/src/genetic_algorithm.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/genetic_algorithm.cpp) |
| [Greedy constructive heuristic](patterns/03-metaheuristics/greedy-constructive/) | C++ | [`Ismael-Sallami/MH-Practices/practice-3/code/src/greedy.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/greedy.cpp) |
| [Hybrid of iterated local search, annealing and a CHC population](patterns/03-metaheuristics/hybrid-ils-annealing-chc/) | C++ | [`Ismael-Sallami/MH-Practices/practice-3/code/src/ils_es_chc.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/ils_es_chc.cpp) |
| [Iterated local search](patterns/03-metaheuristics/iterated-local-search/) | C++ | [`Ismael-Sallami/MH-Practices/practice-3/code/src/ils.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/ils.cpp) |
| [Iterated local search with simulated annealing as the local optimiser](patterns/03-metaheuristics/iterated-local-search-with-annealing/) | C++ | [`Ismael-Sallami/MH-Practices/practice-3/code/src/ils_es.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/ils_es.cpp) |
| [Local search, best improvement](patterns/03-metaheuristics/local-search-best-improvement/) | C++ | [`Ismael-Sallami/MH-Practices/practice-3/code/src/localsearch_best.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/localsearch_best.cpp) |
| [Local search, first improvement](patterns/03-metaheuristics/local-search-first-improvement/) | C++ | [`Ismael-Sallami/MH-Practices/practice-3/code/src/localsearch.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/localsearch.cpp) |
| [Memetic algorithm](patterns/03-metaheuristics/memetic-algorithm/) | C++ | [`Ismael-Sallami/MH-Practices/practice-3/code/src/memetic_algorithm.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/memetic_algorithm.cpp) |
| [Memetic algorithm refining only the best individuals](patterns/03-metaheuristics/memetic-with-selective-refinement/) | C++ | [`Ismael-Sallami/MH-Practices/practice-3/code/src/memetic_lsch.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/memetic_lsch.cpp) |
| [Multistart local search](patterns/03-metaheuristics/multistart-local-search/) | C++ | [`Ismael-Sallami/MH-Practices/practice-3/code/src/localsearch_multistart.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/localsearch_multistart.cpp) |
| [Objective function with constraint repair](patterns/03-metaheuristics/objective-function-and-constraint-repair/) | C++ | [`Ismael-Sallami/MH-Practices/practice-3/code/src/portfolio_problem.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/portfolio_problem.cpp) |
| [Configuration parsing and run reproducibility](patterns/03-metaheuristics/run-reproducibility/) | C++ | [`Ismael-Sallami/MH-Practices/practice-3/code/src/config_reader.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/config_reader.cpp) |
| [Simulated annealing](patterns/03-metaheuristics/simulated-annealing/) | C++ | [`Ismael-Sallami/MH-Practices/practice-3/code/src/simulated_annealing.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/simulated_annealing.cpp) |
| [Bounded-intensity local search](patterns/03-metaheuristics/soft-local-search/) | C++ | [`Ismael-Sallami/MH-Practices/practice-3/code/src/soft_local_search.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/soft_local_search.cpp) |
| [Generating comparison tables across algorithms](patterns/03-metaheuristics/statistical-comparison-tables/) | Python | [`Ismael-Sallami/MH-Practices/practice-3/EXTRA/generar_tablas_comparativas.py`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/EXTRA/generar_tablas_comparativas.py) |

### Concurrency and distributed systems

19 entries.

| Entry | Language | Extracted from |
| --- | --- | --- |
| [Bounded buffer monitor with separate full and empty conditions](patterns/04-concurrency-and-distributed/bounded-buffer-monitor-variant/) | C++ | [`Ismael-Sallami/SCD-Concurrency-MPI/src/Practica3/scd-p3-fuentes/prodcons2.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica3/scd-p3-fuentes/prodcons2.cpp) |
| [Cigarette smokers problem with a monitor](patterns/04-concurrency-and-distributed/cigarette-smokers-monitor/) | C++ | [`Ismael-Sallami/SCD-Concurrency-MPI/src/Practica2/fumadores.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica2/fumadores.cpp) |
| [Cigarette smokers problem with semaphores](patterns/04-concurrency-and-distributed/cigarette-smokers-semaphores/) | C++ | [`Ismael-Sallami/SCD-Concurrency-MPI/src/Practica1/Tercer-Ejercicio/fumadores.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica1/Tercer-Ejercicio/fumadores.cpp) |
| [Cyclic executive with a compressed frame schedule](patterns/04-concurrency-and-distributed/cyclic-executive-compressed/) | C++ | [`Ismael-Sallami/SCD-Concurrency-MPI/src/Practica4/scd-p4-fuentes/ejecutivo1-compr.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica4/scd-p4-fuentes/ejecutivo1-compr.cpp) |
| [Cyclic executive for periodic real-time tasks](patterns/04-concurrency-and-distributed/cyclic-executive-scheduler/) | C++ | [`Ismael-Sallami/SCD-Concurrency-MPI/src/Practica4/scd-p4-fuentes/ejecutivo2.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica4/scd-p4-fuentes/ejecutivo2.cpp) |
| [Dining philosophers, correct solution](patterns/04-concurrency-and-distributed/dining-philosophers/) | C++ | [`Ismael-Sallami/SCD-Concurrency-MPI/src/Practica3/scd-p3-fuentes/filosofos.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica3/scd-p3-fuentes/filosofos.cpp) |
| [Dining philosophers, the deadlocking version](patterns/04-concurrency-and-distributed/dining-philosophers-deadlock/) | C++ | [`Ismael-Sallami/SCD-Concurrency-MPI/src/Practica3/scd-p3-fuentes/filosofos-interb.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica3/scd-p3-fuentes/filosofos-interb.cpp) |
| [Dining philosophers with a waiter](patterns/04-concurrency-and-distributed/dining-philosophers-waiter/) | C++ | [`Ismael-Sallami/SCD-Concurrency-MPI/src/Practica3/scd-p3-fuentes/filosofos-cam.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica3/scd-p3-fuentes/filosofos-cam.cpp) |
| [Measuring worst-case execution time](patterns/04-concurrency-and-distributed/execution-time-measurement/) | C++ | [`Ismael-Sallami/SCD-Concurrency-MPI/src/Practica4/scd-p4-fuentes/tiempos.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica4/scd-p4-fuentes/tiempos.cpp) |
| [Logical clocks over message passing](patterns/04-concurrency-and-distributed/logical-clocks-message-passing/) | C++ | [`Ismael-Sallami/SCD-Concurrency-MPI/src/Practica4/scd-p4-fuentes/relojes.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica4/scd-p4-fuentes/relojes.cpp) |
| [Signal-and-continue monitor semantics](patterns/04-concurrency-and-distributed/monitor-signal-and-continue/) | C++ | [`Ismael-Sallami/SCD-Concurrency-MPI/src/Practica3/scd-p3-fuentes/prodcons.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica3/scd-p3-fuentes/prodcons.cpp) |
| [Signal-and-urgent monitor semantics](patterns/04-concurrency-and-distributed/monitor-signal-and-urgent/) | C++ | [`Ismael-Sallami/SCD-Concurrency-MPI/src/Practica3/scd-p3-fuentes/prodcons2-mu.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica3/scd-p3-fuentes/prodcons2-mu.cpp) |
| [Sieve of Eratosthenes as an MPI process pipeline](patterns/04-concurrency-and-distributed/mpi-pipeline-sieve/) | C++ | [`Ismael-Sallami/SCD-Concurrency-MPI/src/Extra-MPI-Criba/criba.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Extra-MPI-Criba/criba.cpp) |
| [Producer-consumer with a FIFO buffer and counting semaphores](patterns/04-concurrency-and-distributed/producer-consumer-fifo-semaphores/) | C++ | [`Ismael-Sallami/SCD-Concurrency-MPI/src/Practica1/Primer-Ejercicio/prodcons-plantilla_FIFO.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica1/Primer-Ejercicio/prodcons-plantilla_FIFO.cpp) |
| [Producer-consumer with a LIFO buffer](patterns/04-concurrency-and-distributed/producer-consumer-lifo-semaphores/) | C++ | [`Ismael-Sallami/SCD-Concurrency-MPI/src/Practica1/Primer-Ejercicio/prodcons-plantilla_LIFO.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica1/Primer-Ejercicio/prodcons-plantilla_LIFO.cpp) |
| [Producer-consumer as a monitor](patterns/04-concurrency-and-distributed/producer-consumer-monitor/) | C++ | [`Ismael-Sallami/SCD-Concurrency-MPI/src/Practica2/prodconsMultiple.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica2/prodconsMultiple.cpp) |
| [Multiple producers and consumers over a LIFO buffer](patterns/04-concurrency-and-distributed/producer-consumer-multiple-lifo/) | C++ | [`Ismael-Sallami/SCD-Concurrency-MPI/src/Practica1/Segundo-Ejercicio/prodcons-multi-LIFO.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica1/Segundo-Ejercicio/prodcons-multi-LIFO.cpp) |
| [Several producers and several consumers over one buffer](patterns/04-concurrency-and-distributed/producer-consumer-multiple-semaphores/) | C++ | [`Ismael-Sallami/SCD-Concurrency-MPI/src/Practica1/Segundo-Ejercicio/prodcons-multi-FIFO.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica1/Segundo-Ejercicio/prodcons-multi-FIFO.cpp) |
| [Readers-writers with a monitor and condition variables](patterns/04-concurrency-and-distributed/readers-writers-monitor/) | C++ | [`Ismael-Sallami/SCD-Concurrency-MPI/src/Practica2/escritores-lectores.cpp`](https://github.com/Ismael-Sallami/SCD-Concurrency-MPI/blob/main/src/Practica2/escritores-lectores.cpp) |

### Data structures and abstract data types

23 entries.

| Entry | Language | Extracted from |
| --- | --- | --- |
| [Designing the interface of an ADT](patterns/05-data-structures-and-adt/abstract-data-type-interface/) | C++ | [`Ismael-Sallami/TDA-Imagen/ej01_imagenes/estudiante/include/image.h`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/include/image.h) |
| [Composing the containers into an application](patterns/05-data-structures-and-adt/application-composition/) | C++ | [`Ismael-Sallami/Air-lines-Project/rutas_aereas/src/ruta_aerea.cpp`](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/src/ruta_aerea.cpp) |
| [Bidirectional iterator with stream serialisation](patterns/05-data-structures-and-adt/bidirectional-iterator-and-stream-operators/) | C++ | [`Ismael-Sallami/Air-lines-Project/rutas_aereas/src/Ruta.cpp`](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/src/Ruta.cpp) |
| [Reading and writing a binary PGM file](patterns/05-data-structures-and-adt/binary-format-io/) | C++ | [`Ismael-Sallami/TDA-Imagen/ej01_imagenes/estudiante/src/imageIO.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/imageIO.cpp) |
| [Aggregate type ordered by one field](patterns/05-data-structures-and-adt/comparable-aggregate-type/) | C++ | [`Ismael-Sallami/Air-lines-Project/rutas_aereas/src/Pais.cpp`](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/src/Pais.cpp) |
| [Compositing one image onto another through a mask](patterns/05-data-structures-and-adt/composition-with-transparency-mask/) | C++ | [`Ismael-Sallami/Air-lines-Project/rutas_aereas/src/imagen.cpp`](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/src/imagen.cpp) |
| [Hand-written iterator over a 2D container](patterns/05-data-structures-and-adt/custom-forward-iterator/) | C++ | [`Ismael-Sallami/Air-lines-Project/rutas_aereas/src/imagen.cpp`](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/src/imagen.cpp) |
| [Deep copy, assignment and destruction](patterns/05-data-structures-and-adt/deep-copy-and-rule-of-three/) | C++ | [`Ismael-Sallami/TDA-Imagen/ej01_imagenes/estudiante/src/image.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/image.cpp) |
| [Dynamic two-dimensional matrix with manual memory](patterns/05-data-structures-and-adt/dynamic-2d-matrix/) | C++ | [`Ismael-Sallami/TDA-Imagen/ej01_imagenes/estudiante/src/image.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/image.cpp) |
| [Second efficiency study over the same operation](patterns/05-data-structures-and-adt/efficiency-study-variant/) | C++ | [`Ismael-Sallami/TDA-Imagen/ej05_eficiencia/barajar_punto_6.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej05_eficiencia/barajar_punto_6.cpp) |
| [Measuring an algorithm's cost empirically](patterns/05-data-structures-and-adt/empirical-complexity-measurement/) | C++ | [`Ismael-Sallami/TDA-Imagen/ej05_eficiencia/barajar_puntos_1_5.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej05_eficiencia/barajar_puntos_1_5.cpp) |
| [In-place row permutation](patterns/05-data-structures-and-adt/in-place-row-permutation/) | C++ | [`Ismael-Sallami/TDA-Imagen/ej01_imagenes/estudiante/src/imageop.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/imageop.cpp) |
| [Single-index access over two-dimensional storage](patterns/05-data-structures-and-adt/linear-indexing-over-2d-storage/) | C++ | [`Ismael-Sallami/TDA-Imagen/ej01_imagenes/estudiante/src/image.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/image.cpp) |
| [Contrast adjustment through a lookup table](patterns/05-data-structures-and-adt/lookup-table-transform/) | C++ | [`Ismael-Sallami/TDA-Imagen/ej01_imagenes/estudiante/src/imageop.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/imageop.cpp) |
| [Rotating a matrix by an arbitrary angle](patterns/05-data-structures-and-adt/matrix-rotation/) | C++ | [`Ismael-Sallami/Air-lines-Project/rutas_aereas/src/pruebarotacion.cpp`](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/src/pruebarotacion.cpp) |
| [Associative store over an ordered map](patterns/05-data-structures-and-adt/ordered-map-backed-store/) | C++ | [`Ismael-Sallami/Air-lines-Project/rutas_aereas/src/Almacen_Rutas.cpp`](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/src/Almacen_Rutas.cpp) |
| [Zoom by pixel replication and interpolation](patterns/05-data-structures-and-adt/pixel-replication-zoom/) | C++ | [`Ismael-Sallami/TDA-Imagen/ej01_imagenes/estudiante/src/imageop.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/imageop.cpp) |
| [Reading and writing PPM and PGM files](patterns/05-data-structures-and-adt/portable-binary-image-io/) | C++ | [`Ismael-Sallami/Air-lines-Project/rutas_aereas/src/imagenES.cpp`](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/src/imagenES.cpp) |
| [Set-backed store with lookup by two different keys](patterns/05-data-structures-and-adt/set-backed-store-with-multiple-lookups/) | C++ | [`Ismael-Sallami/Air-lines-Project/rutas_aereas/src/Paises.cpp`](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/src/Paises.cpp) |
| [Cropping a submatrix](patterns/05-data-structures-and-adt/submatrix-view/) | C++ | [`Ismael-Sallami/TDA-Imagen/ej01_imagenes/estudiante/src/imageop.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/imageop.cpp) |
| [Composing transforms into a pipeline](patterns/05-data-structures-and-adt/transform-pipeline/) | C++ | [`Ismael-Sallami/TDA-Imagen/ej01_imagenes/estudiante/src/icono.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/icono.cpp) |
| [Value type with comparison and I/O operators](patterns/05-data-structures-and-adt/value-type-with-operators/) | C++ | [`Ismael-Sallami/Air-lines-Project/rutas_aereas/src/Punto.cpp`](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/src/Punto.cpp) |
| [Window mean and subsampling](patterns/05-data-structures-and-adt/window-mean-and-subsample/) | C++ | [`Ismael-Sallami/TDA-Imagen/ej01_imagenes/estudiante/src/imageop.cpp`](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/imageop.cpp) |

### Applied machine learning

5 entries.

| Entry | Language | Extracted from |
| --- | --- | --- |
| [Choosing the number of clusters](patterns/06-applied-machine-learning/cluster-count-selection/) | Python | [`Ismael-Sallami/AA-practices/practice-2/P2_Sallami_Moreno_Ismael.ipynb`](https://github.com/Ismael-Sallami/AA-practices/blob/main/practice-2/P2_Sallami_Moreno_Ismael.ipynb) |
| [Choosing the DBSCAN neighbourhood radius from data](patterns/06-applied-machine-learning/dbscan-epsilon-selection/) | Python | [`Ismael-Sallami/AA-practices/practice-2/P2_Sallami_Moreno_Ismael.ipynb`](https://github.com/Ismael-Sallami/AA-practices/blob/main/practice-2/P2_Sallami_Moreno_Ismael.ipynb) |
| [Comparing classifiers under cross-validation](patterns/06-applied-machine-learning/model-selection-with-cross-validation/) | Python | [`Ismael-Sallami/AA-practices/practice-1/P1_Ismael_Sallami_Moreno.ipynb`](https://github.com/Ismael-Sallami/AA-practices/blob/main/practice-1/P1_Ismael_Sallami_Moreno.ipynb) |
| [Greedy decoding of a sequence-to-sequence model](patterns/06-applied-machine-learning/seq2seq-greedy-decoding/) | Python | [`Ismael-Sallami/AA-practices/project/Proyecto_Sallami_Rodriguez.ipynb`](https://github.com/Ismael-Sallami/AA-practices/blob/main/project/Proyecto_Sallami_Rodriguez.ipynb) |
| [One-hot sequence encoding and network regularisation](patterns/06-applied-machine-learning/sequence-vectorisation-and-regularisation/) | Python | [`Ismael-Sallami/AA-practices/practice-3/P3_SALLAMI_MORENO_ISMAEL.ipynb`](https://github.com/Ismael-Sallami/AA-practices/blob/main/practice-3/P3_SALLAMI_MORENO_ISMAEL.ipynb) |

### Databases and transactions

11 entries.

| Entry | Language | Extracted from |
| --- | --- | --- |
| [Database connection lifecycle](patterns/07-databases-and-transactions/connection-lifecycle/) | Python | [`Ismael-Sallami/DDSI/LaTeX/pr3/src/db_connection.py`](https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/src/db_connection.py) |
| [Verifying credentials against stored hashes](patterns/07-databases-and-transactions/credential-verification/) | Python | [`Ismael-Sallami/DDSI/LaTeX/pr3/src/usuarios/auth.py`](https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/src/usuarios/auth.py) |
| [Aggregation and ranking queries](patterns/07-databases-and-transactions/ranking-aggregation-queries/) | Python | [`Ismael-Sallami/DDSI/LaTeX/pr3/src/tendencias/functions.py`](https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/src/tendencias/functions.py) |
| [Relational schema with declarative constraints](patterns/07-databases-and-transactions/relational-schema-and-constraints/) | SQL | [`Ismael-Sallami/DDSI/LaTeX/pr3/database/00_init_tablas.sql`](https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/database/00_init_tablas.sql) |
| [Server-side procedures](patterns/07-databases-and-transactions/stored-procedures/) | SQL | [`Ismael-Sallami/DDSI/LaTeX/pr3/database/publicidad/procedures_publicidad.sql`](https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/database/publicidad/procedures_publicidad.sql) |
| [Symmetric encryption of stored message bodies](patterns/07-databases-and-transactions/symmetric-encryption-at-rest/) | Python | [`Ismael-Sallami/DDSI/LaTeX/pr3/src/mensajeria/cifrado.py`](https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/src/mensajeria/cifrado.py) |
| [Multi-statement writes with commit and rollback](patterns/07-databases-and-transactions/transactional-write-path/) | Python | [`Ismael-Sallami/DDSI/LaTeX/pr3/src/usuarios/functions.py`](https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/src/usuarios/functions.py) |
| [Business rules enforced by triggers](patterns/07-databases-and-transactions/trigger-based-integrity/) | SQL | [`Ismael-Sallami/DDSI/LaTeX/pr3/database/publicidad/triggers_publicidad.sql`](https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/database/publicidad/triggers_publicidad.sql) |
| [Triggers writing an audit trail](patterns/07-databases-and-transactions/triggers-for-audit-trail/) | SQL | [`Ismael-Sallami/DDSI/LaTeX/pr3/database/mensajeria/triggers_mensajeria.sql`](https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/database/mensajeria/triggers_mensajeria.sql) |
| [Triggers maintaining derived counters](patterns/07-databases-and-transactions/triggers-for-derived-state/) | SQL | [`Ismael-Sallami/DDSI/LaTeX/pr3/database/publicaciones/triggers_publicaciones.sql`](https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/database/publicaciones/triggers_publicaciones.sql) |
| [Triggers maintaining ranking state](patterns/07-databases-and-transactions/triggers-for-ranking-state/) | SQL | [`Ismael-Sallami/DDSI/LaTeX/pr3/database/tendencias/triggers_tendencias.sql`](https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/database/tendencias/triggers_tendencias.sql) |

### Application architecture

18 entries.

| Entry | Language | Extracted from |
| --- | --- | --- |
| [Adapter for an exchange CSV export](patterns/08-application-architecture/adapter-exchange-export/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/parsers/kraken.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/parsers/kraken.py) |
| [Adapter for a multi-section document](patterns/08-application-architecture/adapter-multi-section-document/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/parsers/traderepublic.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/parsers/traderepublic.py) |
| [Adapter tolerating optional and renamed columns](patterns/08-application-architecture/adapter-with-fallback-columns/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/parsers/myinvestor.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/parsers/myinvestor.py) |
| [Aggregating transactions into report figures](patterns/08-application-architecture/aggregation-pipeline/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/aggregation.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/aggregation.py) |
| [Scheduling background jobs](patterns/08-application-architecture/background-job-scheduling/) | Python | [`Ismael-Sallami/personal-finance-manager/app/scheduler.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/scheduler.py) |
| [Backups with a retention policy](patterns/08-application-architecture/backup-with-retention/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/backup.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/backup.py) |
| [Routing bot commands to handlers](patterns/08-application-architecture/command-routing/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/bot.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/bot.py) |
| [Deduplicating files by content hash](patterns/08-application-architecture/content-hash-deduplication/) | Python | [`Ismael-Sallami/media-manager/pythonFiles/comparar_contenido.py`](https://github.com/Ismael-Sallami/media-manager/blob/main/pythonFiles/comparar_contenido.py) |
| [Querying an external price API with a fallback](patterns/08-application-architecture/external-api-with-fallback/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/prices.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/prices.py) |
| [Extracting text from PDF with layered fallbacks](patterns/08-application-architecture/extraction-with-layered-fallbacks/) | Python | [`Ismael-Sallami/pdf-to-md/pdf_to_md.py`](https://github.com/Ismael-Sallami/pdf-to-md/blob/main/src/pdf_to_md.py) |
| [Parsing expenses from free text](patterns/08-application-architecture/free-text-parsing/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/expenses_parse.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/expenses_parse.py) |
| [Generating recurring entries idempotently](patterns/08-application-architecture/idempotent-recurring-entries/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/contributions.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/contributions.py) |
| [Resolving an identifier through a cascade of sources](patterns/08-application-architecture/identifier-resolution-cascade/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/symbol_lookup.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/symbol_lookup.py) |
| [Transforming a markup document into interactive HTML](patterns/08-application-architecture/markup-to-interactive-html/) | Python | [`Ismael-Sallami/md2html-testGenerator/md2html.py`](https://github.com/Ismael-Sallami/md2html-testGenerator/blob/main/src/md2html/core.py) |
| [Fitting and diagnosing a linear regression](patterns/08-application-architecture/ordinary-least-squares-model/) | Python | [`Ismael-Sallami/ModeloEconometrico/Trabajo/trabajo.py`](https://github.com/Ismael-Sallami/ModeloEconometrico/blob/main/Trabajo/trabajo.py) |
| [Password hashing and session tokens](patterns/08-application-architecture/password-hashing-and-sessions/) | Python | [`Ismael-Sallami/personal-finance-manager/app/security.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/security.py) |
| [Profit and loss over a position](patterns/08-application-architecture/profit-and-loss-computation/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/pnl.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/pnl.py) |
| [Dispatching to a parser by strategy](patterns/08-application-architecture/strategy-dispatch/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/parsers/dispatch.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/parsers/dispatch.py) |

### Algorithm design techniques

15 entries.

| Entry | Language | Extracted from |
| --- | --- | --- |
| [Absolute majority by splitting the vote in halves](patterns/09-algorithm-design-techniques/absolute-majority-by-halves/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/01-divide-and-conquer/absolute-majority/absolute_majority_divide.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/01-divide-and-conquer/absolute-majority/absolute_majority_divide.cpp#L18) |
| [Matching nuts to bolts without comparing two of a kind](patterns/09-algorithm-design-techniques/nuts-and-bolts-partition/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/01-divide-and-conquer/nuts-and-bolts/nuts_and_bolts_divide.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/01-divide-and-conquer/nuts-and-bolts/nuts_and_bolts_divide.cpp#L22) |
| [Removing duplicates as a side effect of the merge](patterns/09-algorithm-design-techniques/duplicate-removal-by-merge/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/01-divide-and-conquer/remove-duplicates/remove_duplicates_divide.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/01-divide-and-conquer/remove-duplicates/remove_duplicates_divide.cpp#L10) |
| [Round-robin calendar built by doubling a half-sized one](patterns/09-algorithm-design-techniques/round-robin-calendar-by-doubling/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/01-divide-and-conquer/tournament-calendar/tournament_calendar_divide.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/01-divide-and-conquer/tournament-calendar/tournament_calendar_divide.cpp#L37) |
| [Greedy refuelling: always the furthest station still reachable](patterns/09-algorithm-design-techniques/furthest-reachable-refuelling-stop/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/02-greedy/bus_refuelling.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/02-greedy/bus_refuelling.cpp#L26) |
| [Dijkstra over an adjacency matrix of sensor links](patterns/09-algorithm-design-techniques/dijkstra-over-an-adjacency-matrix/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/02-greedy/sensor_network.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/02-greedy/sensor_network.cpp#L90) |
| [Kruskal with union-find over the streets of a village](patterns/09-algorithm-design-techniques/kruskal-minimum-spanning-tree/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/02-greedy/street_paving.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/02-greedy/street_paving.cpp#L84) |
| [Greedy maximum-weight pairing, and where it settles too early](patterns/09-algorithm-design-techniques/greedy-maximum-weight-pairing/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/02-greedy/student_pairing.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/02-greedy/student_pairing.cpp#L17) |
| [The same pairing by backtracking, which finds what greedy misses](patterns/09-algorithm-design-techniques/backtracking-maximum-weight-pairing/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/03-backtracking-and-branch-and-bound/student_pairing.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/03-backtracking-and-branch-and-bound/student_pairing.cpp#L34) |
| [Seating a circular table by backtracking](patterns/09-algorithm-design-techniques/circular-seating-backtracking/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/03-backtracking-and-branch-and-bound/circular_table.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/03-backtracking-and-branch-and-bound/circular_table.cpp#L22) |
| [Peg solitaire on a 33-square board](patterns/09-algorithm-design-techniques/peg-solitaire-backtracking/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/03-backtracking-and-branch-and-bound/senku.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/03-backtracking-and-branch-and-bound/senku.cpp#L23) |
| [Shortest way out of a maze with a bound on the path](patterns/09-algorithm-design-techniques/maze-shortest-path-branch-and-bound/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/03-backtracking-and-branch-and-bound/maze_branch_and_bound.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/03-backtracking-and-branch-and-bound/maze_branch_and_bound.cpp#L61) |
| [Floyd with a predecessor matrix, so the route can be read back](patterns/09-algorithm-design-techniques/floyd-all-pairs-with-predecessors/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/04-dynamic-programming/flight_times.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/04-dynamic-programming/flight_times.cpp#L8) |
| [Most gold collectable crossing a grid, and the path that does it](patterns/09-algorithm-design-techniques/grid-path-maximisation-with-traceback/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/04-dynamic-programming/gold_grid.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/04-dynamic-programming/gold_grid.cpp#L20) |
| [Cheapest descent of a mountain, filled bottom-up](patterns/09-algorithm-design-techniques/minimum-cost-descent/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/04-dynamic-programming/mountain_descent.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/04-dynamic-programming/mountain_descent.cpp#L11) |


## Written for this repository

No provenance link: these have no prior commit history. Each verifies itself by compiling and running.

### Arrays and hashing

5 entries.

| Entry | Language |
| --- | --- |
| [Difference array](reference/01-arrays-and-hashing/difference-array/) | C++ |
| [Frequency counting](reference/01-arrays-and-hashing/frequency-counting/) | C++ |
| [In place matrix transforms](reference/01-arrays-and-hashing/in-place-matrix-transforms/) | C++ |
| [Prefix sums](reference/01-arrays-and-hashing/prefix-sums/) | C++ |
| [Product except self](reference/01-arrays-and-hashing/product-except-self/) | C++ |

### Two pointers and sliding window

5 entries.

| Entry | Language |
| --- | --- |
| [Container with most water](reference/02-two-pointers-and-sliding-window/container-with-most-water/) | C++ |
| [Cyclic sort and missing values](reference/02-two-pointers-and-sliding-window/cyclic-sort-and-missing-values/) | C++ |
| [Sliding window variable size](reference/02-two-pointers-and-sliding-window/sliding-window-variable-size/) | C++ |
| [Three way partition](reference/02-two-pointers-and-sliding-window/three-way-partition/) | C++ |
| [Two pointer pair sum](reference/02-two-pointers-and-sliding-window/two-pointer-pair-sum/) | C++ |

### Stacks and monotonic structures

1 entries.

| Entry | Language |
| --- | --- |
| [Monotonic structures](reference/03-stack-and-monotonic-structures/monotonic-structures/) | C++ |

### Binary search

1 entries.

| Entry | Language |
| --- | --- |
| [Binary search variants](reference/04-binary-search/binary-search-variants/) | C++ |

### Linked lists

2 entries.

| Entry | Language |
| --- | --- |
| [List surgery and cycles](reference/05-linked-lists/list-surgery-and-cycles/) | C++ |
| [LRU cache](reference/05-linked-lists/lru-cache/) | C++ |

### Trees and tries

6 entries.

| Entry | Language |
| --- | --- |
| [AVL tree](reference/06-trees-and-tries/avl-tree/) | C++ |
| [Binary search tree](reference/06-trees-and-tries/binary-search-tree/) | C++ |
| [Fenwick tree](reference/06-trees-and-tries/fenwick-tree/) | C++ |
| [Segment tree](reference/06-trees-and-tries/segment-tree/) | C++ |
| [Tree traversals](reference/06-trees-and-tries/tree-traversals/) | C++ |
| [Trie](reference/06-trees-and-tries/trie/) | C++ |

### Heaps and priority queues

2 entries.

| Entry | Language |
| --- | --- |
| [Binary heap](reference/07-heaps-and-priority-queues/binary-heap/) | C++ |
| [Quickselect and running median](reference/07-heaps-and-priority-queues/quickselect-and-running-median/) | C++ |

### Backtracking

1 entries.

| Entry | Language |
| --- | --- |
| [Backtracking](reference/08-backtracking/backtracking/) | C++ |

### Graphs

7 entries.

| Entry | Language |
| --- | --- |
| [Bipartite check](reference/09-graphs/bipartite-check/) | C++ |
| [Breadth first search](reference/09-graphs/breadth-first-search/) | C++ |
| [Connected components](reference/09-graphs/connected-components/) | C++ |
| [Depth first search and cycles](reference/09-graphs/depth-first-search-and-cycles/) | C++ |
| [Graph representation](reference/09-graphs/graph-representation/) | C++ |
| [Topological sort](reference/09-graphs/topological-sort/) | C++ |
| [Union find](reference/09-graphs/union-find/) | C++ |

### Advanced graphs

7 entries.

| Entry | Language |
| --- | --- |
| [Bellman-Ford](reference/10-advanced-graphs/bellman-ford/) | C++ |
| [Bridges and articulation points](reference/10-advanced-graphs/bridges-and-articulation-points/) | C++ |
| [Dijkstra's algorithm](reference/10-advanced-graphs/dijkstra/) | C++ |
| [Floyd-Warshall](reference/10-advanced-graphs/floyd-warshall/) | C++ |
| [Maximum flow by Edmonds-Karp](reference/10-advanced-graphs/max-flow-edmonds-karp/) | C++ |
| [Minimum spanning tree](reference/10-advanced-graphs/minimum-spanning-tree/) | C++ |
| [Strongly connected components](reference/10-advanced-graphs/strongly-connected-components/) | C++ |

### Dynamic programming

3 entries.

| Entry | Language |
| --- | --- |
| [Bitmask and interval dynamic programming](reference/11-dynamic-programming/bitmask-and-interval-dp/) | C++ |
| [One-dimensional dynamic programming](reference/11-dynamic-programming/one-dimensional-dp/) | C++ |
| [Sequence alignment](reference/11-dynamic-programming/sequence-alignment/) | C++ |

### Greedy algorithms and intervals

2 entries.

| Entry | Language |
| --- | --- |
| [Huffman coding](reference/12-greedy-and-intervals/huffman-coding/) | C++ |
| [Interval scheduling](reference/12-greedy-and-intervals/interval-scheduling/) | C++ |

### String algorithms

2 entries.

| Entry | Language |
| --- | --- |
| [KMP and the Z-algorithm](reference/13-string-algorithms/kmp-and-z-algorithm/) | C++ |
| [Rolling hash and palindromes](reference/13-string-algorithms/rolling-hash-and-palindromes/) | C++ |

### Mathematics and bit manipulation

2 entries.

| Entry | Language |
| --- | --- |
| [Bit manipulation](reference/14-math-and-bit-manipulation/bit-manipulation/) | C++ |
| [Number theory](reference/14-math-and-bit-manipulation/number-theory/) | C++ |

### Computer architecture

9 entries.

| Entry | Language |
| --- | --- |
| [Booth multiplication](reference/15-computer-architecture/booth-multiplication/) | C++ |
| [Branch predictor](reference/15-computer-architecture/branch-predictor/) | C++ |
| [Cache blocking](reference/15-computer-architecture/cache-blocking/) | C++ |
| [Cache simulator](reference/15-computer-architecture/cache-simulator/) | C++ |
| [Error detection and correction](reference/15-computer-architecture/error-detection-and-correction/) | C++ |
| [IEEE-754 floating point](reference/15-computer-architecture/ieee-754-floating-point/) | C++ |
| [Pipeline hazards](reference/15-computer-architecture/pipeline-hazards/) | C++ |
| [Two's complement arithmetic](reference/15-computer-architecture/twos-complement/) | C++ |
| [Virtual memory translation](reference/15-computer-architecture/virtual-memory-translation/) | C++ |

### Systems primitives

2 entries.

| Entry | Language |
| --- | --- |
| [Bloom filter](reference/16-systems-primitives/bloom-filter/) | C++ |
| [Token bucket rate limiter and consistent hashing](reference/16-systems-primitives/rate-limiter-and-consistent-hashing/) | C++ |

## Author

Ismael Sallami Moreno
