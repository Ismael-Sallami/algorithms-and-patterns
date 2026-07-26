# AVL tree

## Idea

A self-balancing BST. An unbalanced tree degrades to a list on sorted input, turning every operation into O(n); AVL keeps the height within a constant factor of log n by rotating whenever a subtree's children differ in height by more than one.

Four cases, two of them composites: left-left and right-right need one rotation, left-right and right-left need two.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check avl_tree.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
