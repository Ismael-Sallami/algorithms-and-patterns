# Choosing the number of clusters

## Idea

k-means minimises within-cluster variance, which falls monotonically with k, so the objective cannot choose k. Inertia and silhouette are swept across a range and read together. Scaling comes first and is not optional: k-means uses Euclidean distance, so an unscaled feature with a wide range silently dominates the clustering.

## Cost

One clustering per candidate k, each O(n x k x d x iterations).

## Where it is used

Practice 2: unsupervised learning.

## Source

[`machine-learning-practices/src/practice-2-unsupervised-learning.ipynb`](https://github.com/Ismael-Sallami/machine-learning-practices/blob/main/src/practice-2-unsupervised-learning.ipynb#L1) &mdash; notebook cells defining `evaluate_optimal_k`, `perform_eda_and_scaling`.

## Note

scikit-learn provides KMeans and the metrics; the sweep and the preprocessing are the catalogued part.
