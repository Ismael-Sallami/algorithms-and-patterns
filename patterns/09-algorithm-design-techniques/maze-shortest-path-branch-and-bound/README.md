# Shortest way out of a maze with a bound on the path

## Idea

Backtracking finds a way out; this finds the shortest one. The best complete path found so far is the bound, and any branch whose current length already reaches it is abandoned before it is explored. The difference with the backtracking version next to it is one comparison, and it is the difference between an answer and the answer.

## Cost

Exponential in the worst case, but the bound prunes most of it: on the sample maze it explores a small fraction of what plain backtracking does.

## Where it is used

Practical 4 of Algorithmics, problem 5, sharing its maze class with problem 4.

## Source

[`src/03-backtracking-and-branch-and-bound/maze_branch_and_bound.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/03-backtracking-and-branch-and-bound/maze_branch_and_bound.cpp#L61-L108) &mdash; lines 61-108.
