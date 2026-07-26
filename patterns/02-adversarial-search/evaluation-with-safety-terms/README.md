# Evaluation with piece safety and capture terms

## Idea

Adds the terms the baseline misses: pieces on safe squares, pieces exposed to capture, pieces already home. Progress alone makes the agent race a piece up the board and lose it, because the evaluation cannot see the threat that costs more than the progress gained.

## Cost

O(p) per call, with a constant number of terms per piece.

## Where it is used

Second iteration of the Parchis agent.

## Source

[`Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp#L621) &mdash; lines 621-684.
