# Three way partition

## Idea

Dutch national flag: sort an array of three distinct values in one pass.

Three regions grow at once - below, equal, above - separated by three indices. The subtlety is that after swapping with the high region the element now at `mid` has not been examined, so `mid` must not advance; after swapping with the low region it has, so it must. Getting that wrong loses elements.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check three_way_partition.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
