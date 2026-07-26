# Monotonic structures

## Idea

A monotonic stack holds indices whose answer is still unknown, kept in sorted value order. An arriving element resolves every element it dominates at once. Each index is pushed once and popped once, so the total is O(n) even though the inner loop looks quadratic - that amortisation is the whole idea.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check monotonic_structures.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
