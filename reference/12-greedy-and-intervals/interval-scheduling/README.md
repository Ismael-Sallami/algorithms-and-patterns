# Interval scheduling

## Idea

Greedy works when a local choice is provably safe - never worse than any alternative. For intervals, that choice is almost always driven by an end time, and which key you sort by is the entire algorithm.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check interval_scheduling.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
