# One-hot sequence encoding and network regularisation

## Idea

Variable-length token sequences are turned into fixed-width multi-hot vectors so a dense network can consume them, and the network is built with weight decay and dropout. Both exist for the same reason: the vectorised input has far more dimensions than the training set has examples, so an unregularised model memorises it.

## Cost

Vectorisation is O(total tokens) time and O(n x vocabulary) space, which is what bounds the usable vocabulary size.

## Where it is used

Practice 3: neural networks, text classification.

## Source

[`machine-learning-practices/src/practice-3-deep-learning.ipynb`](https://github.com/Ismael-Sallami/machine-learning-practices/blob/main/src/practice-3-deep-learning.ipynb#L1) &mdash; notebook cells defining `vectorizar_secuencias`, `construir_modelo_regularizado`.

## Note

Keras provides the layers and the optimiser; the encoding and the regularisation design are the catalogued part.
