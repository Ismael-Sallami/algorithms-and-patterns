# Trie

## Idea

A prefix tree. A hash set answers "is this word present" just as fast and cannot answer "which words start with this" without scanning everything. That prefix query is the only reason to pay for a trie.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check trie.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
