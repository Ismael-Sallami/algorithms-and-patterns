# Quickselect and running median

## Idea

The k-th smallest element without sorting.

Sorting is O(n log n) and computes far more than asked. Quickselect partitions and then recurses into one side only, so the expected cost is O(n): n + n/2 + n/4 + ... The worst case is O(n^2) on an adversarial pivot sequence, which is why the pivot is chosen at random rather than taken from a fixed position.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check quickselect_and_running_median.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
