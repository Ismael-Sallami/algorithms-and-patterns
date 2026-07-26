# LRU cache

## Idea

Fixed-capacity cache evicting the least recently used entry, O(1) per operation.

Neither structure alone is enough: a hash map gives O(1) lookup and no order, a list gives order and O(n) lookup. Combining them - the map stores an iterator into the list - makes both constant. std::list is what makes it work: splice moves a node without invalidating iterators to it, so the map never needs updating on a promotion.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check lru_cache.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
