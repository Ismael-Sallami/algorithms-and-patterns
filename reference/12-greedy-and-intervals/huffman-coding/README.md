# Huffman coding

## Idea

Huffman coding: the optimal prefix-free code for a known symbol distribution.

The greedy step is to merge the two least frequent symbols repeatedly. It is safe by an exchange argument: in any optimal tree the two rarest symbols can be moved to the deepest pair of sibling leaves without increasing the total, so merging them first loses nothing.

Prefix-free is what makes it decodable without separators - no code is a prefix of another, which falls out of every symbol being a leaf. The result is optimal among per-symbol codes; beating it requires modelling correlations between symbols, which is what arithmetic coding and the LZ family do.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check huffman_coding.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
