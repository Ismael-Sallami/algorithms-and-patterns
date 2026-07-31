# Round-robin calendar built by doubling a half-sized one

## Idea

Every one of n players meets every other exactly once in n-1 days, with n a power of two. Solve it for n/2, then copy that block into the other quadrant and fill the rest with the same block shifted: the top-left and bottom-right quadrants are the two halves playing among themselves, and the other two are the halves playing each other. The calendar for eight is the calendar for four, written twice and displaced.

## Cost

O(n²), which is the size of the table it fills, so it is optimal in the only sense available.

## Where it is used

Practical 2 of Algorithmics. The iterative version produces the same table by rotation and is compared against this one.

## Source

[`src/01-divide-and-conquer/tournament-calendar/tournament_calendar_divide.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/01-divide-and-conquer/tournament-calendar/tournament_calendar_divide.cpp#L37) &mdash; lines 37-50.
