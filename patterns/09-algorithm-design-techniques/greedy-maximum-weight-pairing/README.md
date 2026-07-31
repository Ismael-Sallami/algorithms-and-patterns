# Greedy maximum-weight pairing, and where it settles too early

## Idea

Students are paired two by two and a pair is worth p(i,j) * p(j,i). The greedy answer sorts every possible pair by value and takes them from the top, skipping any student already paired. It is fast and it is often wrong: taking the best pair first can strand two students whose only remaining option is poor, and the total ends up below the optimum. The backtracking entry next to this one solves the same problem and finds those cases.

## Cost

O(n² log n): building the n² pairs and sorting them.

## Where it is used

Practical 3 of Algorithmics. The same statement comes back in practical 4 to be solved properly, which is the reason it is set twice.

## Source

[`src/02-greedy/student_pairing.cpp`](https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/02-greedy/student_pairing.cpp#L17) &mdash; lines 17-46.
