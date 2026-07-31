# Peg solitaire on a 33-square board

## Idea

Thirty-two pegs on a cross-shaped board, one empty square in the middle, and the goal is one peg left in that same middle square. Generate the legal jumps for the current board, try each one, recurse, and undo it if the branch dies. There is no evaluation and no bound: it is depth-first search over the moves, and what makes it finish is that every jump removes a peg, so the depth is exactly thirty-one.

## Cost

Exponential. The board has roughly 10^9 reachable states and the search only survives because each move is irreversible; it takes a few seconds on the standard board.

## Where it is used

Practical 4 of Algorithmics.

## Source

[`src/03-backtracking-and-branch-and-bound/senku.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/03-backtracking-and-branch-and-bound/senku.cpp#L23) &mdash; lines 23-64.
