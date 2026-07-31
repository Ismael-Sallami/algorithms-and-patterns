# The same pairing by backtracking, which finds what greedy misses

## Idea

The pairing problem again, explored exhaustively: take a pair, remove both students from the pool, recurse, and undo. Every complete pairing is scored and the best is kept. Where the greedy version commits to the highest-valued pair and lives with the consequences, this one can give it up when the rest of the board pays better.

## Cost

Exponential in the number of students: the pairings of n students are (n-1)!! Fine for the sizes the practical uses and hopeless beyond them, which is the trade the subject is teaching.

## Where it is used

Practical 4 of Algorithmics, deliberately the same statement as practical 3 so the two answers can be compared.

## Source

[`src/03-backtracking-and-branch-and-bound/student_pairing.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/03-backtracking-and-branch-and-bound/student_pairing.cpp#L34-L61) &mdash; lines 34-61.
