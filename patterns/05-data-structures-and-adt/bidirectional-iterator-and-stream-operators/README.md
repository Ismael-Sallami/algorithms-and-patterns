# Bidirectional iterator with stream serialisation

## Idea

A route is an ordered sequence of points with a full bidirectional iterator pair, plus overloaded >> and << so a route reads and writes as text. Serialisation through the stream operators means the container composes: reading a collection of routes is one loop over the same operator.

## Cost

O(1) per iterator step, O(n) per serialised route.

## Where it is used

Route storage and the on-disk route format.

## Source

[`airline-routes-adt/src/Ruta.cpp`](https://github.com/Ismael-Sallami/airline-routes-adt/blob/main/src/Ruta.cpp#L6-L168) &mdash; complete file.
