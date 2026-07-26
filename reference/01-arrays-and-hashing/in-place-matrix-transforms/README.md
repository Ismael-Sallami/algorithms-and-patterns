# In place matrix transforms

## Idea

Rotating a square matrix 90 degrees clockwise with no second matrix.

Transpose, then reverse each row. Transposing reflects across the main diagonal, reversing reflects across the vertical axis, and two reflections compose into a rotation. Two simple passes avoid the index arithmetic of a four-way cycle swap.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check in_place_matrix_transforms.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
