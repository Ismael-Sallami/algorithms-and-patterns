# Binary search tree

## Idea

An unbalanced binary search tree, written to show where deletion is hard. Insert and lookup are the easy half; the three deletion cases are the reason this is worth writing out rather than assuming.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check binary_search_tree.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
