# Breadth-first search over a grid state space

## Idea

Level-by-level expansion from the start state with a FIFO queue and a closed list. Because every move costs the same at this level, the first time the goal is dequeued the plan is optimal in number of steps. The state carries the agent orientation, so the same cell appears up to eight times in the graph and the closed list has to key on the full state.

## Cost

O(V + E) time, O(V) space. Here V = rows x cols x 8 orientations and every node has 3 successors (advance, turn left, turn right), so E = 3V.

## Where it is used

Level 1 of the rescuer agent: plan a route to a seen but not yet reached cell, on a map where all traversable terrain costs the same.

## Source

[`Practica2_IA/practica2/rescatador.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/rescatador.cpp#L1222) &mdash; lines 1222-1302.
