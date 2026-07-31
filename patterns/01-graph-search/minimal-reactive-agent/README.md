# Minimal reactive agent

## Idea

The smallest complete agent in the simulation: read the sensor, pick an action, no state at all. Kept as the floor of the comparison - it establishes what a policy with no memory and no model can achieve, which is what the planning agents have to beat.

## Cost

O(1) time and O(1) space per decision.

## Where it is used

The hiker agent in the multi-agent simulation.

## Source

[`rescue-agents/docs/earlier-iterations/excursionista.cpp`](https://github.com/Ismael-Sallami/rescue-agents/blob/main/docs/earlier-iterations/excursionista.cpp#L1) &mdash; complete file.
