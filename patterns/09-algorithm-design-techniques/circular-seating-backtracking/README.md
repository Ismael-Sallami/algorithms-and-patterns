# Seating a circular table by backtracking

## Idea

Guests sit around one round table and each neighbouring pair has a convenience value. Fix the first guest to kill the rotational symmetry, then place the rest one at a time, marking each as used and unmarking on the way back. The convenience is accumulated as the seats are filled and the closing pair, last guest with first, is added when the circle completes.

## Cost

O(n!) placements, cut by the fixed first seat to (n-1)!.

## Where it is used

Practical 4 of Algorithmics, next to the greedy version of the same problem in practical 3.

## Source

[`src/03-backtracking-and-branch-and-bound/circular_table.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/03-backtracking-and-branch-and-bound/circular_table.cpp#L22-L46) &mdash; lines 22-46.
