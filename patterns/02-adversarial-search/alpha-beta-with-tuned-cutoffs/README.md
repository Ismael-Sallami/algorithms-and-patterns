# Alpha-beta with tuned cutoff conditions

## Idea

Alpha-beta with the terminal test widened: as well as depth and game over, it stops on a decisive evaluation, because expanding a position that is already won or lost cannot change the move. Correctness rests on the bound being genuinely unrecoverable, which is why the threshold is set from the evaluation's own range rather than picked.

## Cost

Same bounds as alpha-beta with a smaller effective depth on decided positions.

## Where it is used

Later configuration of the Parchis agent.

## Source

[`Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp#L1354) &mdash; lines 1354-1425.
