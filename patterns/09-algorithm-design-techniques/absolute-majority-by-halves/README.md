# Absolute majority by splitting the vote in halves

## Idea

Split the ballot in two, ask each half for its candidate, and only then count. A candidate with more than n/2 votes overall has to hold the absolute majority in at least one half, so the two halves between them can only propose two candidates and each one is confirmed with a single pass. The recursion never returns a candidate that has to be searched for later: it returns one that only needs counting.

## Cost

O(n log n). Each level costs a linear count and there are log n levels. The iterative version next to it is O(n) with Boyer-Moore, which is the point the practical makes: divide and conquer is not automatically the faster answer.

## Where it is used

Practical 2 of Algorithmics, alongside an iterative version and a hybrid that switches between the two at a measured threshold.

## Source

[`src/01-divide-and-conquer/absolute-majority/absolute_majority_divide.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/01-divide-and-conquer/absolute-majority/absolute_majority_divide.cpp#L18) &mdash; lines 18-55.
