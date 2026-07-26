# One-dimensional dynamic programming

## Idea

Four steps turn a recurrence into a table: identify the state, write the transition, order the states so dependencies come first, and decide how much of the table has to be kept. That last step is where most of the space savings live.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check one_dimensional_dp.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
