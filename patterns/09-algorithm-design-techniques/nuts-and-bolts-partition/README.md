# Matching nuts to bolts without comparing two of a kind

## Idea

You may compare a nut to a bolt and learn which is bigger, but never a nut to a nut. That rules out sorting either side on its own. The way round it is a double quicksort: take a bolt, partition the nuts against it, and the nut that matches falls out as the pivot; then partition the bolts against that nut. Each partition gives the pivot for the other side.

## Cost

O(n log n) expected, O(n²) worst case, exactly like quicksort and for the same reason: the pivot is whatever the input hands you.

## Where it is used

Practical 2 of Algorithmics. The iterative version alongside it sorts both sides with counting sort, which is faster here but only works because the sizes are small integers.

## Source

[`src/01-divide-and-conquer/nuts-and-bolts/nuts_and_bolts_divide.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/01-divide-and-conquer/nuts-and-bolts/nuts_and_bolts_divide.cpp#L22-L47) &mdash; lines 22-47.
