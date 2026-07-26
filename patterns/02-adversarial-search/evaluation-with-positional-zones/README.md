# Evaluation with positional zones and distance bands

## Idea

Scores a piece by the zone it stands in rather than its raw coordinate, because the value of a square is not linear in the distance to home - the final corridor and the safe squares are worth more than their position suggests. Bands make that non-linearity expressible without a table per square.

## Cost

O(p) per call with a constant zone lookup per piece.

## Where it is used

Fourth iteration of the Parchis agent.

## Source

[`Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp#L881) &mdash; lines 881-930.
