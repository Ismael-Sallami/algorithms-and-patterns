# Catalogue

198 implementations: 141 extracted from earlier work and 57 written for this repository.

## Extracted from earlier work

Each row links to the folder and to the file it was sliced out of.

### Graph and state-space search

13 entries.

| Entry | Language | Extracted from |
| --- | --- | --- |
| [A* with a Manhattan-distance heuristic](patterns/01-graph-search/a-star-manhattan/) | C++ | [`Ismael-Sallami/rescue-agents/src/rescatador.cpp`](https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/rescatador.cpp#L1733) |
| [A* re-targeted at a resupply point when the primary goal is unreachable](patterns/01-graph-search/a-star-with-secondary-objective/) | C++ | [`Ismael-Sallami/rescue-agents/src/auxiliar.cpp`](https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/auxiliar.cpp#L1302) |
| [Best-first selection of the next cell to explore](patterns/01-graph-search/best-first-frontier-selection/) | C++ | [`Ismael-Sallami/rescue-agents/src/rescatador.cpp`](https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/rescatador.cpp#L1650) |
| [Breadth-first search over a grid state space](patterns/01-graph-search/breadth-first-search/) | C++ | [`Ismael-Sallami/rescue-agents/src/rescatador.cpp`](https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/rescatador.cpp#L1222) |
| [Dijkstra over a weighted grid with composite state](patterns/01-graph-search/dijkstra-on-a-grid/) | C++ | [`Ismael-Sallami/rescue-agents/src/rescatador.cpp`](https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/rescatador.cpp#L1444) |
| [Scoring frontier cells by surrounding unknown area](patterns/01-graph-search/frontier-scoring-by-unknown-neighbours/) | C++ | [`Ismael-Sallami/rescue-agents/src/auxiliar.cpp`](https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/auxiliar.cpp#L1534) |
| [Reactive agent driven by a target predicate](patterns/01-graph-search/goal-directed-reactive-agent/) | C++ | [`Ismael-Sallami/rescue-agents/docs/earlier-iterations/vandalo.cpp`](https://github.com/Ismael-Sallami/rescue-agents/blob/main/docs/earlier-iterations/vandalo.cpp#L1) |
| [Layered reactive control without a plan](patterns/01-graph-search/layered-reactive-control/) | C++ | [`Ismael-Sallami/rescue-agents/src/rescatador.cpp`](https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/rescatador.cpp#L121) |
| [Minimal reactive agent](patterns/01-graph-search/minimal-reactive-agent/) | C++ | [`Ismael-Sallami/rescue-agents/docs/earlier-iterations/excursionista.cpp`](https://github.com/Ismael-Sallami/rescue-agents/blob/main/docs/earlier-iterations/excursionista.cpp#L1) |
| [Legal move generation with collision avoidance](patterns/01-graph-search/move-generation-with-collision-avoidance/) | C++ | [`Ismael-Sallami/rescue-agents/src/rescatador.cpp`](https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/rescatador.cpp#L528) |
| [Breaking movement loops with visit counters](patterns/01-graph-search/revisit-counting-to-break-loops/) | C++ | [`Ismael-Sallami/rescue-agents/src/rescatador.cpp`](https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/rescatador.cpp#L500) |
| [Projecting a local sensor reading onto a global map](patterns/01-graph-search/sensor-to-map-projection/) | C++ | [`Ismael-Sallami/rescue-agents/src/auxiliar.cpp`](https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/auxiliar.cpp#L378) |
| [State transition function and edge cost model](patterns/01-graph-search/state-transition-and-cost-model/) | C++ | [`Ismael-Sallami/rescue-agents/src/rescatador.cpp`](https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/rescatador.cpp#L1164) |

### Adversarial search

15 entries.

| Entry | Language | Extracted from |
| --- | --- | --- |
| [Probabilistic cutoff in a chance node tree](patterns/02-adversarial-search/alpha-beta-probabilistic/) | C++ | [`Ismael-Sallami/parchis-ai/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L1139) |
| [Probabilistic alpha-beta with depth-dependent ordering](patterns/02-adversarial-search/alpha-beta-probabilistic-dynamic-ordering/) | C++ | [`Ismael-Sallami/parchis-ai/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L1213) |
| [Alpha-beta pruning](patterns/02-adversarial-search/alpha-beta-pruning/) | C++ | [`Ismael-Sallami/parchis-ai/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L530) |
| [Alpha-beta with move ordering](patterns/02-adversarial-search/alpha-beta-with-move-ordering/) | C++ | [`Ismael-Sallami/parchis-ai/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L692) |
| [Alpha-beta with tuned cutoff conditions](patterns/02-adversarial-search/alpha-beta-with-tuned-cutoffs/) | C++ | [`Ismael-Sallami/parchis-ai/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L1354) |
| [Minimax with a hard node budget](patterns/02-adversarial-search/depth-limited-minimax/) | C++ | [`Ismael-Sallami/parchis-ai/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L458) |
| [Baseline evaluation function](patterns/02-adversarial-search/evaluation-baseline/) | C++ | [`Ismael-Sallami/parchis-ai/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L342) |
| [Evaluation whose weights follow the game phase](patterns/02-adversarial-search/evaluation-with-dynamic-weights/) | C++ | [`Ismael-Sallami/parchis-ai/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L940) |
| [Evaluation with positional zones and distance bands](patterns/02-adversarial-search/evaluation-with-positional-zones/) | C++ | [`Ismael-Sallami/parchis-ai/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L881) |
| [Evaluation with piece safety and capture terms](patterns/02-adversarial-search/evaluation-with-safety-terms/) | C++ | [`Ismael-Sallami/parchis-ai/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L621) |
| [Weighted linear evaluation over hand-picked features](patterns/02-adversarial-search/evaluation-with-weighted-features/) | C++ | [`Ismael-Sallami/parchis-ai/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L766) |
| [Greedy and random move policies](patterns/02-adversarial-search/greedy-move-policies/) | C++ | [`Ismael-Sallami/parchis-ai/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L156) |
| [Evaluation function with weights that follow the game phase](patterns/02-adversarial-search/heuristic-evaluation-and-dynamic-weights/) | C++ | [`Ismael-Sallami/parchis-ai/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L940) |
| [Minimax over a game tree](patterns/02-adversarial-search/minimax/) | C++ | [`Ismael-Sallami/parchis-ai/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L401) |
| [Quiescence search at the horizon](patterns/02-adversarial-search/quiescence-search/) | C++ | [`Ismael-Sallami/parchis-ai/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L1025) |

### Metaheuristics and continuous optimisation

22 entries.

| Entry | Language | Extracted from |
| --- | --- | --- |
| [Unit tests for the optimisation components](patterns/03-metaheuristics/algorithm-unit-tests/) | C++ | [`Ismael-Sallami/metaheuristics/src/practice-1/tests/test.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-1/tests/test.cpp#L1) |
| [Basic multistart with a shared best](patterns/03-metaheuristics/basic-multistart-search/) | C++ | [`Ismael-Sallami/metaheuristics/src/practice-3/src/bmb.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-3/src/bmb.cpp#L4) |
| [Convergence curves and boxplot comparison](patterns/03-metaheuristics/convergence-curves/) | Python | [`Ismael-Sallami/metaheuristics/src/practice-3/extra/convergencia_comparativa.py`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-3/extra/convergencia_comparativa.py#L2) |
| [Parsing delimited numeric series](patterns/03-metaheuristics/delimited-data-parsing/) | C++ | [`Ismael-Sallami/metaheuristics/src/practice-1/src/csv_reader.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-1/src/csv_reader.cpp#L11) |
| [Differential evolution](patterns/03-metaheuristics/differential-evolution/) | C++ | [`Ismael-Sallami/metaheuristics/src/practice-2/src/differential_evolution.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-2/src/differential_evolution.cpp#L4) |
| [Repeated-run protocol with mean and standard deviation](patterns/03-metaheuristics/experimental-protocol/) | C++ | [`Ismael-Sallami/metaheuristics/src/practice-2/main.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-2/main.cpp#L111) |
| [Gaussian mutation with boundary handling](patterns/03-metaheuristics/gaussian-mutation/) | C++ | [`Ismael-Sallami/metaheuristics/src/practice-2/src/gaussian_mutation.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-2/src/gaussian_mutation.cpp#L7) |
| [Genetic algorithm, generational and steady-state](patterns/03-metaheuristics/genetic-algorithm/) | C++ | [`Ismael-Sallami/metaheuristics/src/practice-2/src/genetic_algorithm.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-2/src/genetic_algorithm.cpp#L6) |
| [Greedy constructive heuristic](patterns/03-metaheuristics/greedy-constructive/) | C++ | [`Ismael-Sallami/metaheuristics/src/practice-2/src/greedy.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-2/src/greedy.cpp#L7) |
| [Hybrid of iterated local search, annealing and a CHC population](patterns/03-metaheuristics/hybrid-ils-annealing-chc/) | C++ | [`Ismael-Sallami/metaheuristics/src/practice-3/src/ils_es_chc.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-3/src/ils_es_chc.cpp#L7) |
| [Iterated local search](patterns/03-metaheuristics/iterated-local-search/) | C++ | [`Ismael-Sallami/metaheuristics/src/practice-3/src/ils.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-3/src/ils.cpp#L7) |
| [Iterated local search with simulated annealing as the local optimiser](patterns/03-metaheuristics/iterated-local-search-with-annealing/) | C++ | [`Ismael-Sallami/metaheuristics/src/practice-3/src/ils_es.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-3/src/ils_es.cpp#L3) |
| [Local search, best improvement](patterns/03-metaheuristics/local-search-best-improvement/) | C++ | [`Ismael-Sallami/metaheuristics/src/practice-2/src/localsearch_best.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-2/src/localsearch_best.cpp#L8) |
| [Local search, first improvement](patterns/03-metaheuristics/local-search-first-improvement/) | C++ | [`Ismael-Sallami/metaheuristics/src/practice-3/src/localsearch.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-3/src/localsearch.cpp#L7) |
| [Memetic algorithm](patterns/03-metaheuristics/memetic-algorithm/) | C++ | [`Ismael-Sallami/metaheuristics/src/practice-2/src/memetic_algorithm.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-2/src/memetic_algorithm.cpp#L7) |
| [Memetic algorithm refining only the best individuals](patterns/03-metaheuristics/memetic-with-selective-refinement/) | C++ | [`Ismael-Sallami/metaheuristics/src/practice-2/src/memetic_lsch.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-2/src/memetic_lsch.cpp#L6) |
| [Multistart local search](patterns/03-metaheuristics/multistart-local-search/) | C++ | [`Ismael-Sallami/metaheuristics/src/practice-2/src/localsearch_multistart.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-2/src/localsearch_multistart.cpp#L7) |
| [Objective function with constraint repair](patterns/03-metaheuristics/objective-function-and-constraint-repair/) | C++ | [`Ismael-Sallami/metaheuristics/src/practice-2/src/portfolio_problem.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-2/src/portfolio_problem.cpp#L5) |
| [Configuration parsing and run reproducibility](patterns/03-metaheuristics/run-reproducibility/) | C++ | [`Ismael-Sallami/metaheuristics/src/practice-3/src/config_reader.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-3/src/config_reader.cpp#L6) |
| [Simulated annealing](patterns/03-metaheuristics/simulated-annealing/) | C++ | [`Ismael-Sallami/metaheuristics/src/practice-3/src/simulated_annealing.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-3/src/simulated_annealing.cpp#L7) |
| [Bounded-intensity local search](patterns/03-metaheuristics/soft-local-search/) | C++ | [`Ismael-Sallami/metaheuristics/src/practice-2/src/soft_local_search.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-2/src/soft_local_search.cpp#L7) |
| [Generating comparison tables across algorithms](patterns/03-metaheuristics/statistical-comparison-tables/) | Python | [`Ismael-Sallami/metaheuristics/src/practice-3/extra/generar_tablas_comparativas.py`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-3/extra/generar_tablas_comparativas.py#L2) |

### Concurrency and distributed systems

19 entries.

| Entry | Language | Extracted from |
| --- | --- | --- |
| [Bounded buffer monitor with separate full and empty conditions](patterns/04-concurrency-and-distributed/bounded-buffer-monitor-variant/) | C++ | [`Ismael-Sallami/concurrency-mpi/src/practice-3-mpi/producer-consumer-buffer.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-3-mpi/producer-consumer-buffer.cpp#L22) |
| [Cigarette smokers problem with a monitor](patterns/04-concurrency-and-distributed/cigarette-smokers-monitor/) | C++ | [`Ismael-Sallami/concurrency-mpi/src/practice-2-monitors/smokers.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-2-monitors/smokers.cpp#L9) |
| [Cigarette smokers problem with semaphores](patterns/04-concurrency-and-distributed/cigarette-smokers-semaphores/) | C++ | [`Ismael-Sallami/concurrency-mpi/src/practice-1-semaphores/smokers/smokers.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-1-semaphores/smokers/smokers.cpp#L9) |
| [Cyclic executive with a compressed frame schedule](patterns/04-concurrency-and-distributed/cyclic-executive-compressed/) | C++ | [`Ismael-Sallami/concurrency-mpi/src/practice-4-realtime/cyclic-executive-1-checked.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-4-realtime/cyclic-executive-1-checked.cpp#L7) |
| [Cyclic executive for periodic real-time tasks](patterns/04-concurrency-and-distributed/cyclic-executive-scheduler/) | C++ | [`Ismael-Sallami/concurrency-mpi/src/practice-4-realtime/cyclic-executive-2.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-4-realtime/cyclic-executive-2.cpp#L35) |
| [Dining philosophers, correct solution](patterns/04-concurrency-and-distributed/dining-philosophers/) | C++ | [`Ismael-Sallami/concurrency-mpi/src/practice-3-mpi/philosophers.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-3-mpi/philosophers.cpp#L15) |
| [Dining philosophers, the deadlocking version](patterns/04-concurrency-and-distributed/dining-philosophers-deadlock/) | C++ | [`Ismael-Sallami/concurrency-mpi/src/practice-3-mpi/philosophers-deadlock.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-3-mpi/philosophers-deadlock.cpp#L21) |
| [Dining philosophers with a waiter](patterns/04-concurrency-and-distributed/dining-philosophers-waiter/) | C++ | [`Ismael-Sallami/concurrency-mpi/src/practice-3-mpi/philosophers-waiter.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-3-mpi/philosophers-waiter.cpp#L21) |
| [Measuring worst-case execution time](patterns/04-concurrency-and-distributed/execution-time-measurement/) | C++ | [`Ismael-Sallami/concurrency-mpi/src/practice-4-realtime/timing.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-4-realtime/timing.cpp#L19) |
| [Logical clocks over message passing](patterns/04-concurrency-and-distributed/logical-clocks-message-passing/) | C++ | [`Ismael-Sallami/concurrency-mpi/src/practice-4-realtime/clocks.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-4-realtime/clocks.cpp#L19) |
| [Signal-and-continue monitor semantics](patterns/04-concurrency-and-distributed/monitor-signal-and-continue/) | C++ | [`Ismael-Sallami/concurrency-mpi/src/practice-3-mpi/producer-consumer.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-3-mpi/producer-consumer.cpp#L22) |
| [Signal-and-urgent monitor semantics](patterns/04-concurrency-and-distributed/monitor-signal-and-urgent/) | C++ | [`Ismael-Sallami/concurrency-mpi/src/practice-3-mpi/producer-consumer-multi.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-3-mpi/producer-consumer-multi.cpp#L22) |
| [Sieve of Eratosthenes as an MPI process pipeline](patterns/04-concurrency-and-distributed/mpi-pipeline-sieve/) | C++ | [`Ismael-Sallami/concurrency-mpi/src/extra-mpi-sieve/notes.txt`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/extra-mpi-sieve/notes.txt#L12) |
| [Producer-consumer with a FIFO buffer and counting semaphores](patterns/04-concurrency-and-distributed/producer-consumer-fifo-semaphores/) | C++ | [`Ismael-Sallami/concurrency-mpi/src/practice-1-semaphores/producer-consumer/prodcons-fifo.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-1-semaphores/producer-consumer/prodcons-fifo.cpp#L8) |
| [Producer-consumer with a LIFO buffer](patterns/04-concurrency-and-distributed/producer-consumer-lifo-semaphores/) | C++ | [`Ismael-Sallami/concurrency-mpi/src/practice-1-semaphores/producer-consumer/prodcons-lifo.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-1-semaphores/producer-consumer/prodcons-lifo.cpp#L8) |
| [Producer-consumer as a monitor](patterns/04-concurrency-and-distributed/producer-consumer-monitor/) | C++ | [`Ismael-Sallami/concurrency-mpi/src/practice-2-monitors/producer-consumer-multi.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-2-monitors/producer-consumer-multi.cpp#L26) |
| [Multiple producers and consumers over a LIFO buffer](patterns/04-concurrency-and-distributed/producer-consumer-multiple-lifo/) | C++ | [`Ismael-Sallami/concurrency-mpi/src/practice-1-semaphores/producer-consumer-multi/prodcons-multi-lifo.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-1-semaphores/producer-consumer-multi/prodcons-multi-lifo.cpp#L8) |
| [Several producers and several consumers over one buffer](patterns/04-concurrency-and-distributed/producer-consumer-multiple-semaphores/) | C++ | [`Ismael-Sallami/concurrency-mpi/src/practice-1-semaphores/producer-consumer-multi/prodcons-multi-fifo.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-1-semaphores/producer-consumer-multi/prodcons-multi-fifo.cpp#L8) |
| [Readers-writers with a monitor and condition variables](patterns/04-concurrency-and-distributed/readers-writers-monitor/) | C++ | [`Ismael-Sallami/concurrency-mpi/src/practice-2-monitors/readers-writers.cpp`](https://github.com/Ismael-Sallami/concurrency-mpi/blob/main/src/practice-2-monitors/readers-writers.cpp#L11) |

### Data structures and abstract data types

23 entries.

| Entry | Language | Extracted from |
| --- | --- | --- |
| [Designing the interface of an ADT](patterns/05-data-structures-and-adt/abstract-data-type-interface/) | C++ | [`Ismael-Sallami/image-adt/include/image.h`](https://github.com/Ismael-Sallami/image-adt/blob/main/include/image.h#L1) |
| [Composing the containers into an application](patterns/05-data-structures-and-adt/application-composition/) | C++ | [`Ismael-Sallami/airline-routes-adt/src/ruta_aerea.cpp`](https://github.com/Ismael-Sallami/airline-routes-adt/blob/main/src/ruta_aerea.cpp#L11) |
| [Bidirectional iterator with stream serialisation](patterns/05-data-structures-and-adt/bidirectional-iterator-and-stream-operators/) | C++ | [`Ismael-Sallami/airline-routes-adt/src/Ruta.cpp`](https://github.com/Ismael-Sallami/airline-routes-adt/blob/main/src/Ruta.cpp#L6) |
| [Reading and writing a binary PGM file](patterns/05-data-structures-and-adt/binary-format-io/) | C++ | [`Ismael-Sallami/image-adt/src/imageIO.cpp`](https://github.com/Ismael-Sallami/image-adt/blob/main/src/imageIO.cpp#L1) |
| [Aggregate type ordered by one field](patterns/05-data-structures-and-adt/comparable-aggregate-type/) | C++ | [`Ismael-Sallami/airline-routes-adt/src/Pais.cpp`](https://github.com/Ismael-Sallami/airline-routes-adt/blob/main/src/Pais.cpp#L2) |
| [Compositing one image onto another through a mask](patterns/05-data-structures-and-adt/composition-with-transparency-mask/) | C++ | [`Ismael-Sallami/airline-routes-adt/src/imagen.cpp`](https://github.com/Ismael-Sallami/airline-routes-adt/blob/main/src/imagen.cpp#L221) |
| [Hand-written iterator over a 2D container](patterns/05-data-structures-and-adt/custom-forward-iterator/) | C++ | [`Ismael-Sallami/airline-routes-adt/src/imagen.cpp`](https://github.com/Ismael-Sallami/airline-routes-adt/blob/main/src/imagen.cpp#L6) |
| [Deep copy, assignment and destruction](patterns/05-data-structures-and-adt/deep-copy-and-rule-of-three/) | C++ | [`Ismael-Sallami/image-adt/src/image.cpp`](https://github.com/Ismael-Sallami/image-adt/blob/main/src/image.cpp#L75) |
| [Dynamic two-dimensional matrix with manual memory](patterns/05-data-structures-and-adt/dynamic-2d-matrix/) | C++ | [`Ismael-Sallami/image-adt/src/image.cpp`](https://github.com/Ismael-Sallami/image-adt/blob/main/src/image.cpp#L37) |
| [Second efficiency study over the same operation](patterns/05-data-structures-and-adt/efficiency-study-variant/) | C++ | [`Ismael-Sallami/image-adt/src/barajar.cpp`](https://github.com/Ismael-Sallami/image-adt/blob/main/src/barajar.cpp#L12) |
| [Measuring an algorithm's cost empirically](patterns/05-data-structures-and-adt/empirical-complexity-measurement/) | C++ | [`Ismael-Sallami/image-adt/src/efficiency-study/barajar_puntos_1_5.cpp`](https://github.com/Ismael-Sallami/image-adt/blob/main/src/efficiency-study/barajar_puntos_1_5.cpp#L12) |
| [In-place row permutation](patterns/05-data-structures-and-adt/in-place-row-permutation/) | C++ | [`Ismael-Sallami/image-adt/src/imageop.cpp`](https://github.com/Ismael-Sallami/image-adt/blob/main/src/imageop.cpp#L104) |
| [Single-index access over two-dimensional storage](patterns/05-data-structures-and-adt/linear-indexing-over-2d-storage/) | C++ | [`Ismael-Sallami/image-adt/src/image.cpp`](https://github.com/Ismael-Sallami/image-adt/blob/main/src/image.cpp#L208) |
| [Contrast adjustment through a lookup table](patterns/05-data-structures-and-adt/lookup-table-transform/) | C++ | [`Ismael-Sallami/image-adt/src/imageop.cpp`](https://github.com/Ismael-Sallami/image-adt/blob/main/src/imageop.cpp#L24) |
| [Rotating a matrix by an arbitrary angle](patterns/05-data-structures-and-adt/matrix-rotation/) | C++ | [`Ismael-Sallami/airline-routes-adt/src/pruebarotacion.cpp`](https://github.com/Ismael-Sallami/airline-routes-adt/blob/main/src/pruebarotacion.cpp#L5) |
| [Associative store over an ordered map](patterns/05-data-structures-and-adt/ordered-map-backed-store/) | C++ | [`Ismael-Sallami/airline-routes-adt/src/Almacen_Rutas.cpp`](https://github.com/Ismael-Sallami/airline-routes-adt/blob/main/src/Almacen_Rutas.cpp#L3) |
| [Zoom by pixel replication and interpolation](patterns/05-data-structures-and-adt/pixel-replication-zoom/) | C++ | [`Ismael-Sallami/image-adt/src/imageop.cpp`](https://github.com/Ismael-Sallami/image-adt/blob/main/src/imageop.cpp#L117) |
| [Reading and writing PPM and PGM files](patterns/05-data-structures-and-adt/portable-binary-image-io/) | C++ | [`Ismael-Sallami/airline-routes-adt/src/imagenES.cpp`](https://github.com/Ismael-Sallami/airline-routes-adt/blob/main/src/imagenES.cpp#L1) |
| [Set-backed store with lookup by two different keys](patterns/05-data-structures-and-adt/set-backed-store-with-multiple-lookups/) | C++ | [`Ismael-Sallami/airline-routes-adt/src/Paises.cpp`](https://github.com/Ismael-Sallami/airline-routes-adt/blob/main/src/Paises.cpp#L2) |
| [Cropping a submatrix](patterns/05-data-structures-and-adt/submatrix-view/) | C++ | [`Ismael-Sallami/image-adt/src/imageop.cpp`](https://github.com/Ismael-Sallami/image-adt/blob/main/src/imageop.cpp#L71) |
| [Composing transforms into a pipeline](patterns/05-data-structures-and-adt/transform-pipeline/) | C++ | [`Ismael-Sallami/image-adt/src/icono.cpp`](https://github.com/Ismael-Sallami/image-adt/blob/main/src/icono.cpp#L11) |
| [Value type with comparison and I/O operators](patterns/05-data-structures-and-adt/value-type-with-operators/) | C++ | [`Ismael-Sallami/airline-routes-adt/src/Punto.cpp`](https://github.com/Ismael-Sallami/airline-routes-adt/blob/main/src/Punto.cpp#L3) |
| [Window mean and subsampling](patterns/05-data-structures-and-adt/window-mean-and-subsample/) | C++ | [`Ismael-Sallami/image-adt/src/imageop.cpp`](https://github.com/Ismael-Sallami/image-adt/blob/main/src/imageop.cpp#L43) |

### Applied machine learning

5 entries.

| Entry | Language | Extracted from |
| --- | --- | --- |
| [Choosing the number of clusters](patterns/06-applied-machine-learning/cluster-count-selection/) | Python | [`Ismael-Sallami/machine-learning-practices/src/practice-2-unsupervised-learning.ipynb`](https://github.com/Ismael-Sallami/machine-learning-practices/blob/main/src/practice-2-unsupervised-learning.ipynb#L1) |
| [Choosing the DBSCAN neighbourhood radius from data](patterns/06-applied-machine-learning/dbscan-epsilon-selection/) | Python | [`Ismael-Sallami/machine-learning-practices/src/practice-2-unsupervised-learning.ipynb`](https://github.com/Ismael-Sallami/machine-learning-practices/blob/main/src/practice-2-unsupervised-learning.ipynb#L1) |
| [Comparing classifiers under cross-validation](patterns/06-applied-machine-learning/model-selection-with-cross-validation/) | Python | [`Ismael-Sallami/machine-learning-practices/src/practice-1-supervised-learning.ipynb`](https://github.com/Ismael-Sallami/machine-learning-practices/blob/main/src/practice-1-supervised-learning.ipynb#L1) |
| [Greedy decoding of a sequence-to-sequence model](patterns/06-applied-machine-learning/seq2seq-greedy-decoding/) | Python | [`Ismael-Sallami/machine-learning-practices/src/project-seq2seq-chatbot.ipynb`](https://github.com/Ismael-Sallami/machine-learning-practices/blob/main/src/project-seq2seq-chatbot.ipynb#L1) |
| [One-hot sequence encoding and network regularisation](patterns/06-applied-machine-learning/sequence-vectorisation-and-regularisation/) | Python | [`Ismael-Sallami/machine-learning-practices/src/practice-3-deep-learning.ipynb`](https://github.com/Ismael-Sallami/machine-learning-practices/blob/main/src/practice-3-deep-learning.ipynb#L1) |

### Databases and transactions

11 entries.

| Entry | Language | Extracted from |
| --- | --- | --- |
| [Database connection lifecycle](patterns/07-databases-and-transactions/connection-lifecycle/) | Python | [`Ismael-Sallami/oracle-dbms-project/src/db_connection.py`](https://github.com/Ismael-Sallami/oracle-dbms-project/blob/main/src/db_connection.py#L1) |
| [Verifying credentials against stored hashes](patterns/07-databases-and-transactions/credential-verification/) | Python | [`Ismael-Sallami/oracle-dbms-project/src/usuarios/auth.py`](https://github.com/Ismael-Sallami/oracle-dbms-project/blob/main/src/usuarios/auth.py#L1) |
| [Aggregation and ranking queries](patterns/07-databases-and-transactions/ranking-aggregation-queries/) | Python | [`Ismael-Sallami/oracle-dbms-project/src/tendencias/functions.py`](https://github.com/Ismael-Sallami/oracle-dbms-project/blob/main/src/tendencias/functions.py#L2) |
| [Relational schema with declarative constraints](patterns/07-databases-and-transactions/relational-schema-and-constraints/) | SQL | [`Ismael-Sallami/oracle-dbms-project/database/00_init_tablas.sql`](https://github.com/Ismael-Sallami/oracle-dbms-project/blob/main/database/00_init_tablas.sql#L1) |
| [Server-side procedures](patterns/07-databases-and-transactions/stored-procedures/) | SQL | [`Ismael-Sallami/oracle-dbms-project/database/publicidad/procedures_publicidad.sql`](https://github.com/Ismael-Sallami/oracle-dbms-project/blob/main/database/publicidad/procedures_publicidad.sql#L1) |
| [Symmetric encryption of stored message bodies](patterns/07-databases-and-transactions/symmetric-encryption-at-rest/) | Python | [`Ismael-Sallami/oracle-dbms-project/src/mensajeria/cifrado.py`](https://github.com/Ismael-Sallami/oracle-dbms-project/blob/main/src/mensajeria/cifrado.py#L1) |
| [Multi-statement writes with commit and rollback](patterns/07-databases-and-transactions/transactional-write-path/) | Python | [`Ismael-Sallami/oracle-dbms-project/src/usuarios/functions.py`](https://github.com/Ismael-Sallami/oracle-dbms-project/blob/main/src/usuarios/functions.py#L8) |
| [Business rules enforced by triggers](patterns/07-databases-and-transactions/trigger-based-integrity/) | SQL | [`Ismael-Sallami/oracle-dbms-project/database/publicidad/triggers_publicidad.sql`](https://github.com/Ismael-Sallami/oracle-dbms-project/blob/main/database/publicidad/triggers_publicidad.sql#L1) |
| [Triggers writing an audit trail](patterns/07-databases-and-transactions/triggers-for-audit-trail/) | SQL | [`Ismael-Sallami/oracle-dbms-project/database/mensajeria/triggers_mensajeria.sql`](https://github.com/Ismael-Sallami/oracle-dbms-project/blob/main/database/mensajeria/triggers_mensajeria.sql#L1) |
| [Triggers maintaining derived counters](patterns/07-databases-and-transactions/triggers-for-derived-state/) | SQL | [`Ismael-Sallami/oracle-dbms-project/database/publicaciones/triggers_publicaciones.sql`](https://github.com/Ismael-Sallami/oracle-dbms-project/blob/main/database/publicaciones/triggers_publicaciones.sql#L2) |
| [Triggers maintaining ranking state](patterns/07-databases-and-transactions/triggers-for-ranking-state/) | SQL | [`Ismael-Sallami/oracle-dbms-project/database/tendencias/triggers_tendencias.sql`](https://github.com/Ismael-Sallami/oracle-dbms-project/blob/main/database/tendencias/triggers_tendencias.sql#L1) |

### Application architecture

18 entries.

| Entry | Language | Extracted from |
| --- | --- | --- |
| [Adapter for an exchange CSV export](patterns/08-application-architecture/adapter-exchange-export/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/parsers/kraken.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/parsers/kraken.py#L1) |
| [Adapter for a multi-section document](patterns/08-application-architecture/adapter-multi-section-document/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/parsers/traderepublic.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/parsers/traderepublic.py#L1) |
| [Adapter tolerating optional and renamed columns](patterns/08-application-architecture/adapter-with-fallback-columns/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/parsers/myinvestor.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/parsers/myinvestor.py#L1) |
| [Aggregating transactions into report figures](patterns/08-application-architecture/aggregation-pipeline/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/aggregation.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/aggregation.py#L1) |
| [Scheduling background jobs](patterns/08-application-architecture/background-job-scheduling/) | Python | [`Ismael-Sallami/personal-finance-manager/app/scheduler.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/scheduler.py#L1) |
| [Backups with a retention policy](patterns/08-application-architecture/backup-with-retention/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/backup.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/backup.py#L1) |
| [Routing bot commands to handlers](patterns/08-application-architecture/command-routing/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/bot.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/bot.py#L1) |
| [Deduplicating files by content hash](patterns/08-application-architecture/content-hash-deduplication/) | Python | [`Ismael-Sallami/media-manager/src/compare.py`](https://github.com/Ismael-Sallami/media-manager/blob/main/src/compare.py#L1) |
| [Querying an external price API with a fallback](patterns/08-application-architecture/external-api-with-fallback/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/prices.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/prices.py#L1) |
| [Extracting text from PDF with layered fallbacks](patterns/08-application-architecture/extraction-with-layered-fallbacks/) | Python | [`Ismael-Sallami/pdf-to-md/src/pdf_to_md.py`](https://github.com/Ismael-Sallami/pdf-to-md/blob/main/src/pdf_to_md.py#L2) |
| [Parsing expenses from free text](patterns/08-application-architecture/free-text-parsing/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/expenses_parse.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/expenses_parse.py#L1) |
| [Generating recurring entries idempotently](patterns/08-application-architecture/idempotent-recurring-entries/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/contributions.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/contributions.py#L1) |
| [Resolving an identifier through a cascade of sources](patterns/08-application-architecture/identifier-resolution-cascade/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/symbol_lookup.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/symbol_lookup.py#L1) |
| [Transforming a markup document into interactive HTML](patterns/08-application-architecture/markup-to-interactive-html/) | Python | [`Ismael-Sallami/md2html-testGenerator/src/md2html/core.py`](https://github.com/Ismael-Sallami/md2html-testGenerator/blob/main/src/md2html/core.py#L1) |
| [Fitting and diagnosing a linear regression](patterns/08-application-architecture/ordinary-least-squares-model/) | Python | [`Ismael-Sallami/econometric-model/src/model.py`](https://github.com/Ismael-Sallami/econometric-model/blob/main/src/model.py#L2) |
| [Password hashing and session tokens](patterns/08-application-architecture/password-hashing-and-sessions/) | Python | [`Ismael-Sallami/personal-finance-manager/app/security.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/security.py#L1) |
| [Profit and loss over a position](patterns/08-application-architecture/profit-and-loss-computation/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/pnl.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/pnl.py#L1) |
| [Dispatching to a parser by strategy](patterns/08-application-architecture/strategy-dispatch/) | Python | [`Ismael-Sallami/personal-finance-manager/app/services/parsers/dispatch.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/parsers/dispatch.py#L1) |

### Algorithm design techniques

15 entries.

| Entry | Language | Extracted from |
| --- | --- | --- |
| [Absolute majority by splitting the vote in halves](patterns/09-algorithm-design-techniques/absolute-majority-by-halves/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/01-divide-and-conquer/absolute-majority/absolute_majority_divide.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/01-divide-and-conquer/absolute-majority/absolute_majority_divide.cpp#L18-L55) |
| [Matching nuts to bolts without comparing two of a kind](patterns/09-algorithm-design-techniques/nuts-and-bolts-partition/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/01-divide-and-conquer/nuts-and-bolts/nuts_and_bolts_divide.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/01-divide-and-conquer/nuts-and-bolts/nuts_and_bolts_divide.cpp#L22-L47) |
| [Removing duplicates as a side effect of the merge](patterns/09-algorithm-design-techniques/duplicate-removal-by-merge/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/01-divide-and-conquer/remove-duplicates/remove_duplicates_divide.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/01-divide-and-conquer/remove-duplicates/remove_duplicates_divide.cpp#L10-L43) |
| [Round-robin calendar built by doubling a half-sized one](patterns/09-algorithm-design-techniques/round-robin-calendar-by-doubling/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/01-divide-and-conquer/tournament-calendar/tournament_calendar_divide.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/01-divide-and-conquer/tournament-calendar/tournament_calendar_divide.cpp#L37-L50) |
| [Greedy refuelling: always the furthest station still reachable](patterns/09-algorithm-design-techniques/furthest-reachable-refuelling-stop/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/02-greedy/bus_refuelling.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/02-greedy/bus_refuelling.cpp#L26-L52) |
| [Dijkstra over an adjacency matrix of sensor links](patterns/09-algorithm-design-techniques/dijkstra-over-an-adjacency-matrix/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/02-greedy/sensor_network.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/02-greedy/sensor_network.cpp#L90-L146) |
| [Kruskal with union-find over the streets of a village](patterns/09-algorithm-design-techniques/kruskal-minimum-spanning-tree/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/02-greedy/street_paving.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/02-greedy/street_paving.cpp#L84-L107) |
| [Greedy maximum-weight pairing, and where it settles too early](patterns/09-algorithm-design-techniques/greedy-maximum-weight-pairing/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/02-greedy/student_pairing.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/02-greedy/student_pairing.cpp#L17-L46) |
| [The same pairing by backtracking, which finds what greedy misses](patterns/09-algorithm-design-techniques/backtracking-maximum-weight-pairing/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/03-backtracking-and-branch-and-bound/student_pairing.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/03-backtracking-and-branch-and-bound/student_pairing.cpp#L34-L61) |
| [Seating a circular table by backtracking](patterns/09-algorithm-design-techniques/circular-seating-backtracking/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/03-backtracking-and-branch-and-bound/circular_table.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/03-backtracking-and-branch-and-bound/circular_table.cpp#L22-L46) |
| [Peg solitaire on a 33-square board](patterns/09-algorithm-design-techniques/peg-solitaire-backtracking/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/03-backtracking-and-branch-and-bound/senku.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/03-backtracking-and-branch-and-bound/senku.cpp#L23-L64) |
| [Shortest way out of a maze with a bound on the path](patterns/09-algorithm-design-techniques/maze-shortest-path-branch-and-bound/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/03-backtracking-and-branch-and-bound/maze_branch_and_bound.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/03-backtracking-and-branch-and-bound/maze_branch_and_bound.cpp#L61-L108) |
| [Floyd with a predecessor matrix, so the route can be read back](patterns/09-algorithm-design-techniques/floyd-all-pairs-with-predecessors/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/04-dynamic-programming/flight_times.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/04-dynamic-programming/flight_times.cpp#L8-L28) |
| [Most gold collectable crossing a grid, and the path that does it](patterns/09-algorithm-design-techniques/grid-path-maximisation-with-traceback/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/04-dynamic-programming/gold_grid.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/04-dynamic-programming/gold_grid.cpp#L20-L59) |
| [Cheapest descent of a mountain, filled bottom-up](patterns/09-algorithm-design-techniques/minimum-cost-descent/) | C++ | [`Ismael-Sallami/algorithm-design-techniques/src/04-dynamic-programming/mountain_descent.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/04-dynamic-programming/mountain_descent.cpp#L11-L41) |


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
