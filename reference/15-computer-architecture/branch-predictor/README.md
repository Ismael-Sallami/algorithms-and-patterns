# Branch predictor

## Idea

Dynamic branch prediction.

A pipelined processor must fetch the next instruction before the current branch has resolved, so it guesses. A wrong guess costs the whole pipeline refill - fifteen or twenty cycles on a deep pipeline - which is why a few percent of accuracy is worth real hardware.

One-bit predictor: remember what the branch did last time. It mispredicts twice per loop, on entry and on exit, because a single bit flips on any surprise. For a tight inner loop that runs a few times, that is most of the branches.

Two-bit saturating counter: the state must be wrong twice in a row before the prediction flips. That one change removes one of the two loop mispredictions, which is why two bits is the standard and three rarely pays for itself.

00 strongly not taken -> 01 weakly not taken -> 10 weakly taken -> 11 strongly taken

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check branch_predictor.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
