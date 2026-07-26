# Cyclic sort and missing values

## Idea

When values are a permutation of 1..n, the array can index itself: value v belongs at position v-1. Placing each value where it belongs takes O(n) overall, because every swap puts one value in its final place, and a single scan then reveals what is missing or duplicated. No hash set and no extra allocation.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check cyclic_sort_and_missing_values.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
