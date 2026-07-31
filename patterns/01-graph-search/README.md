# Graph and state-space search

Shortest paths and reachability over a grid whose state is more than a coordinate pair. Every algorithm here runs inside an agent that only sees part of the map, so the search is re-planned as the map is discovered.

6 patterns.

| Pattern | Language | Source |
| --- | --- | --- |
| [Breadth-first search over a grid state space](breadth-first-search/) | C++ | [`rescue-agents`](https://github.com/Ismael-Sallami/rescue-agents) |
| [Dijkstra over a weighted grid with composite state](dijkstra-on-a-grid/) | C++ | [`rescue-agents`](https://github.com/Ismael-Sallami/rescue-agents) |
| [A* with a Manhattan-distance heuristic](a-star-manhattan/) | C++ | [`rescue-agents`](https://github.com/Ismael-Sallami/rescue-agents) |
| [A* re-targeted at a resupply point when the primary goal is unreachable](a-star-with-secondary-objective/) | C++ | [`rescue-agents`](https://github.com/Ismael-Sallami/rescue-agents) |
| [Best-first selection of the next cell to explore](best-first-frontier-selection/) | C++ | [`rescue-agents`](https://github.com/Ismael-Sallami/rescue-agents) |
| [State transition function and edge cost model](state-transition-and-cost-model/) | C++ | [`rescue-agents`](https://github.com/Ismael-Sallami/rescue-agents) |

[Back to the catalogue](../../README.md)
