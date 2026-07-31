# Cheapest descent of a mountain, filled bottom-up

## Idea

Each square of the mountain has a cost and you may step straight down or diagonally. The table is filled row by row: the cost of reaching a square is its own plus the cheapest of the three squares above it that can reach it. The first row is the base case and needs no minimum. Same shape as the gold problem and opposite objective, which is what makes the pair worth reading together.

## Cost

O(n·m), one minimum of three per square.

## Where it is used

Practical 5 of Algorithmics.

## Source

[`src/04-dynamic-programming/mountain_descent.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/04-dynamic-programming/mountain_descent.cpp#L11-L41) &mdash; lines 11-41.
