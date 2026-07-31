# Removing duplicates as a side effect of the merge

## Idea

Split, remove duplicates in each half, and merge discarding equal keys as they meet. The interesting part is what falls out for free: the result comes back sorted, because the merge is the merge of merge sort. The iterative version keeps the original order and this one does not, so the two agree as sets and not as text, and the test in the source repository compares them that way.

## Cost

O(n log n), the cost of the merge sort it is built on. The iterative version is O(n²) comparing each element against those already kept.

## Where it is used

Practical 2 of Algorithmics.

## Source

[`src/01-divide-and-conquer/remove-duplicates/remove_duplicates_divide.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/01-divide-and-conquer/remove-duplicates/remove_duplicates_divide.cpp#L10-L43) &mdash; lines 10-43.
