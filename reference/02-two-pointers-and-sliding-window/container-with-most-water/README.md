# Container with most water

## Idea

Largest rectangle between two of n vertical lines.

Area is distance times the shorter line. Starting from the widest pair, moving the taller line inwards can never help: the width shrinks and the height is still capped by the shorter line. So only the shorter one is worth moving, and that discards a candidate per step - O(n) instead of the O(n^2) pair scan.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check container_with_most_water.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
