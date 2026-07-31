# Most gold collectable crossing a grid, and the path that does it

## Idea

Cross a grid from top-left to bottom-right collecting gold, moving only right or diagonally down. The table holds the best haul reachable at each square and is filled in one pass; squares that cannot be reached are marked as minus infinity rather than zero, which matters because zero is a legal amount of gold and unreachable is not. The path is recovered afterwards by walking the table backwards, choosing at each step the neighbour that justifies the value.

## Cost

O(n·m) to fill the table and O(n+m) to walk it back.

## Where it is used

Practical 5 of Algorithmics.

## Source

[`src/04-dynamic-programming/gold_grid.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/04-dynamic-programming/gold_grid.cpp#L20-L59) &mdash; lines 20-59.
