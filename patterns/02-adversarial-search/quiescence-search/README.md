# Quiescence search at the horizon

## Idea

A fixed depth limit can stop the search in the middle of an exchange and return an evaluation that a single further move would overturn - the horizon effect. Quiescence search extends the recursion past the limit while forcing moves remain, and stops only at a position where the evaluation is stable.

## Cost

O(b_q^d_q) on top of the main search, where b_q is the number of forcing moves. Much smaller than b because only captures qualify.

## Where it is used

Applied at the leaves of the main search to stop the agent from walking into an exchange it cannot see the end of.

## Source

[`Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp#L1025) &mdash; lines 1025-1107.
