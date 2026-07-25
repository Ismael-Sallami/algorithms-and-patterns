# A* with a Manhattan-distance heuristic

## Idea

Dijkstra with the queue keyed on cost-so-far plus an estimate of cost-to-go. The estimate is the Manhattan distance to the target, which never overestimates on a grid whose cheapest move costs at least one, so the heuristic is admissible and the first expansion of the goal is optimal. The gain over Dijkstra is that expansion is pulled towards the target instead of spreading evenly in all directions.

## Cost

Same worst case as Dijkstra, O((V + E) log V). In practice it expands far fewer nodes; the closer the heuristic is to the true cost, the narrower the explored band.

## Where it is used

Level 4 of the rescuer agent, planning long routes across a partly known map where re-planning happens often and expansion count matters.

## Source

[`Practica2_IA/practica2/rescatador.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/rescatador.cpp#L1733) &mdash; lines 1733-1826.
