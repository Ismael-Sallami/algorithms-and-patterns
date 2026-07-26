# Product except self

## Idea

Product of every element except the current one, without division.

Division would be one pass and breaks on any zero in the input. Instead: one left-to-right pass accumulating the product of everything before each position, then one right-to-left pass multiplying in everything after. The output array carries the left products, so the extra space is O(1).

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check product_except_self.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
