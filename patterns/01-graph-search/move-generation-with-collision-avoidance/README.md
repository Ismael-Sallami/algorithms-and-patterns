# Legal move generation with collision avoidance

## Idea

Enumerates the moves that are legal from the current cell - terrain passable, height difference survivable, no other agent in the way - and returns them ranked. Keeping generation separate from selection means the reactive layer and the planners consume the same definition of a legal move, so the two can never disagree about what is reachable.

## Cost

O(1) per call: at most three candidate actions, each checked against a fixed number of conditions.

## Where it is used

Successor generation for both the reactive layers and the search algorithms.

## Source

[`rescue-agents/src/rescatador.cpp`](https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/rescatador.cpp#L528) &mdash; lines 528-662, 683-692.
