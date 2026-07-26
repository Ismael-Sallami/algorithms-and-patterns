# Sequence alignment

## Idea

Two-dimensional DP over a pair of sequences. The state is a pair of prefix lengths, and every transition consumes at least one character from one side, which is what makes the table acyclic and fills it in row order.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check sequence_alignment.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
