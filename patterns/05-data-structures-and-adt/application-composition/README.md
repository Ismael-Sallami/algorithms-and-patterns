# Composing the containers into an application

## Idea

The layer that ties the containers together: read the country set and the route store from disk, resolve a route to its sequence of coordinates, render it onto the map. Nothing algorithmic happens here, and that is what it demonstrates - every piece of logic is behind an interface, so this file is only wiring.

## Cost

Dominated by the rendering pass, O(map area) per frame.

## Where it is used

The entry point of the air routes project.

## Source

[`Air-lines-Project/rutas_aereas/src/ruta_aerea.cpp`](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/src/ruta_aerea.cpp#L1) &mdash; complete file.
