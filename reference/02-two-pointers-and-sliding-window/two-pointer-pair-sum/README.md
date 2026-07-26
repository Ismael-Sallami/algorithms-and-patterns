# Two pointer pair sum

## Idea

Finds a pair summing to target in a sorted array. Two indices walking inwards: if the sum is too small only moving the left pointer helps, if too large only moving the right one does. Every step eliminates a whole row or column of the pair space, which is why one pass replaces the O(n^2) scan.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check two_pointer_pair_sum.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
