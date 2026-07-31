# Floyd with a predecessor matrix, so the route can be read back

## Idea

Shortest flight time between every pair of airports, stopovers included, with a penalty added per stop. Floyd's triple loop over intermediate airports, plus a second matrix recording which airport was used as the stopover whenever it improved the time. Without that matrix the algorithm answers how long and not through where, and the second half of the problem is unanswerable.

## Cost

O(n³) time and O(n²) space, twice over for the two matrices.

## Where it is used

Practical 5 of Algorithmics, the dynamic programming one.

## Source

[`src/04-dynamic-programming/flight_times.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/04-dynamic-programming/flight_times.cpp#L8-L28) &mdash; lines 8-28.
