# Reactive agent driven by a target predicate

## Idea

A third agent with a different objective on the same map and the same sensors. It shows the split that matters in agent design: perception and movement are shared, and only the goal predicate and the rule priorities change. Nothing in the perception layer knows what this agent wants.

## Cost

O(1) per decision. No planning and no accumulated map.

## Where it is used

The vandal agent in the multi-agent simulation.

## Source

[`Practica2_IA/IA_Practica2/Comportamientos_Jugador/vandalo.cpp`](https://github.com/Ismael-Sallami/Practica2_IA/blob/main/IA_Practica2/Comportamientos_Jugador/vandalo.cpp#L1) &mdash; complete file.
