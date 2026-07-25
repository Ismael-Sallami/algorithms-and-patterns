# Greedy constructive heuristic

## Idea

Builds one solution by repeatedly committing to the locally best remaining choice and never revisiting it. Cheap and deterministic, which makes it the reference every stochastic method has to beat, and a sensible starting point for local search.

## Cost

O(n^2) for n assets: n commitments, each scanning the remaining candidates. One objective evaluation per candidate.

## Where it is used

Portfolio allocation: choose the weight of each asset to maximise risk-adjusted return, subject to per-asset bounds and weights that sum to one. Trained on 2015-2024 and tested on 2025.

## Source

[`MH-Practices/practice-3/code/src/greedy.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/greedy.cpp#L1) &mdash; complete file.
