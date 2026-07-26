# Bridges and articulation points

## Idea

A comma inside a template argument makes the preprocessor read assert() as taking two arguments, so the type needs a name of its own.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check bridges_and_articulation_points.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
