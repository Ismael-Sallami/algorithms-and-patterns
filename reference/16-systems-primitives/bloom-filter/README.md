# Bloom filter

## Idea

A Bloom filter answers set membership in constant time and constant space per element, with one deliberate compromise: it can say yes to something absent, but never no to something present.

That asymmetry is what makes it useful. A database can consult a Bloom filter before touching disk - a "no" is certain, so the disk read is skipped entirely, and a "yes" costs only the read that would have happened anyway. False positives cost work, never correctness.

k hash functions set k bits per insertion. Too few and different elements collide on the same bit; too many and the array fills up. The optimum is k = (m/n) ln 2 for m bits and n elements, giving a false positive rate of about 0.6185^(m/n) - roughly 1% at 10 bits per element.

Deletion is impossible: clearing a bit could unset one shared with another element. A counting Bloom filter replaces each bit with a small counter to allow it, at several times the space.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check bloom_filter.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
