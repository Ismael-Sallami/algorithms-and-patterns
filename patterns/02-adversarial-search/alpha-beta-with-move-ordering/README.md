# Alpha-beta with move ordering

## Idea

Alpha-beta preceded by a cheap sort of the children by static evaluation, best first. Pruning only fires after a good bound has been established, so the order children are visited in decides how much of the tree is cut. Sorting costs O(b log b) per node and pays for itself several times over.

## Cost

Same bounds as alpha-beta, but ordering pushes the real cost towards the O(b^(d/2)) end. Sorting adds O(b log b) per internal node.

## Where it is used

The variant the agent actually plays with at higher depths.

## Source

[`Parcherckers/src/AIPlayer.cpp`](https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp#L692) &mdash; lines 692-757.
