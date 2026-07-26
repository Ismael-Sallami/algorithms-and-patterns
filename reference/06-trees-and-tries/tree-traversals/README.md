# Tree traversals

## Idea

The three depth-first orders differ only in when the node is emitted relative to its children. Recursion makes that obvious; the iterative forms make the stack explicit, which is what matters when the depth can exceed the call stack.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check tree_traversals.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
