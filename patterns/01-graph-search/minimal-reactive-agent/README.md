# Minimal reactive agent

## Idea

The smallest complete agent in the simulation: read the sensor, pick an action, no state at all. Kept as the floor of the comparison - it establishes what a policy with no memory and no model can achieve, which is what the planning agents have to beat.

## Cost

O(1) time and O(1) space per decision.

## Where it is used

The hiker agent in the multi-agent simulation.

## Source

[`Practica2_IA/IA_Practica2/Comportamientos_Jugador/excursionista.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/IA_Practica2/Comportamientos_Jugador/excursionista.cpp#L1) &mdash; complete file.
