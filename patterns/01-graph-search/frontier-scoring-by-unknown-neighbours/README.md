# Scoring frontier cells by surrounding unknown area

## Idea

Ranks candidate exploration targets by how many unknown cells surround them, so the agent walks towards the places that reveal the most map per step. Distance is folded into the same score, which stops it from crossing the map for a marginally better frontier.

## Cost

O(n) to score n candidates with a constant-size neighbourhood scan, then O(n log n) to order them.

## Where it is used

The discovery phase of the auxiliary agent.

## Source

[`Practica2_IA/practica2/auxiliar.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/auxiliar.cpp#L1534) &mdash; lines 1534-1553, 1556-1579.
