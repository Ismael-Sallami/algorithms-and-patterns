# Greedy decoding of a sequence-to-sequence model

## Idea

Inference for an encoder-decoder model: encode the input once, then feed each predicted token back in as the next input until the stop token or the length cap. Training runs on the whole target sequence at once, so the decoding loop has to be written separately - it is inherently sequential and cannot be batched over time.

## Cost

O(output length) forward passes through the decoder, one per token. The encoder runs once.

## Where it is used

Final project: sequence-to-sequence model.

## Source

[`AA-practices/project/Proyecto_Sallami_Rodriguez.ipynb`](https://github.com/Ismael-Sallami/AA-practices/blob/main/project/Proyecto_Sallami_Rodriguez.ipynb) &mdash; notebook cells defining `decode_sequence`.

## Note

Keras provides the model; the decoding loop is the catalogued part.
