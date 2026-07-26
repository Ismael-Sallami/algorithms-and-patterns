# Frequency counting

## Idea

Top k most frequent values. Counting is O(n); the interesting choice is how to extract the top k.

Bucket sort by frequency is O(n), because a frequency can never exceed n so there are at most n+1 buckets. Sorting the counts is O(m log m) and a size-k heap is O(m log k). Bucketing wins when k approaches m.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check frequency_counting.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
