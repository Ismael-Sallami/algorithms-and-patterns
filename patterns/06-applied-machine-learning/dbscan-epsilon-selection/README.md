# Choosing the DBSCAN neighbourhood radius from data

## Idea

DBSCAN needs a radius, and picking it by hand decides the result. Two data-driven choices are implemented: the knee of the sorted k-distance curve, and the value that maximises the silhouette score. Where the two agree the choice is defensible; where they disagree the data has no clear density scale, which is itself worth knowing.

## Cost

The k-distance curve costs a k-nearest-neighbour query per point, O(n log n) with a spatial index. The silhouette sweep costs one clustering plus one O(n^2) silhouette per candidate.

## Where it is used

Practice 2: unsupervised learning.

## Source

[`AA-practices/practice-2/P2_Sallami_Moreno_Ismael.ipynb`](https://github.com/Ismael-Sallami/AA-practices/blob/main/practice-2/P2_Sallami_Moreno_Ismael.ipynb) &mdash; notebook cells defining `calcular_epsilon_optimo`, `justificar_epsilon_por_silueta`.

## Note

scikit-learn provides DBSCAN and the silhouette metric; the selection procedure is the catalogued part.
