# Cache simulator

## Idea

A set-associative cache simulator.

An address splits into three fields, and the split is the whole design:

| tag | set index | block offset |

block offset  picks the byte inside a block  (log2 of the block size) set index     picks which set the block maps to  (log2 of the set count) tag           what is left, stored to identify the block

Associativity is the number of blocks per set. One block per set is direct mapped: fastest lookup, and two hot addresses mapping to the same set evict each other forever - conflict misses. One set holding everything is fully associative: no conflict misses, and every lookup compares every tag. Real caches sit between, typically 4 to 16 ways, because the conflict curve flattens quickly and the comparator cost does not.

The three kinds of miss need different fixes, which is why separating them matters: compulsory  first reference to a block; only prefetching helps capacity    the working set exceeds the cache; only a bigger cache helps conflict    enough room, wrong mapping; more associativity helps

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check cache_simulator.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
