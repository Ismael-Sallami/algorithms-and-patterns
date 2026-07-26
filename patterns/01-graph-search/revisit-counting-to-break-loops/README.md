# Breaking movement loops with visit counters

## Idea

A purely reactive agent on a symmetric map cycles: the same reading produces the same action forever. Counting visits per cell and forcing a different action once a threshold is crossed breaks the cycle. The counter is the minimum state a memoryless policy needs to stop repeating itself.

## Cost

O(1) per check with an O(rows x cols) counter matrix.

## Where it is used

Levels 0 and 1 of the rescuer agent, where no plan exists to follow.

## Source

[`Practica2_IA/practica2/rescatador.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/rescatador.cpp#L500) &mdash; lines 500-507, 518-526.
