# Difference array

## Idea

Many range updates followed by reads. Applying each update directly costs O(range); recording only the boundaries costs O(1) per update and one O(n) pass to materialise the result.

Adding delta to [from, to] means +delta at from and -delta just past to. A prefix sum over those marks reproduces every update at once.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check difference_array.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
