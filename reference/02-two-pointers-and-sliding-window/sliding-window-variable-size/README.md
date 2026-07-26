# Sliding window variable size

## Idea

Longest substring with no repeated character. The window is valid when it holds no duplicate; on a repeat the left edge jumps straight past the previous occurrence rather than sliding one step at a time. That jump keeps the total at O(n), because each index is visited once by each pointer.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check sliding_window_variable_size.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
