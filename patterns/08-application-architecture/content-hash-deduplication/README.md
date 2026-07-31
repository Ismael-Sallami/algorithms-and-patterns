# Deduplicating files by content hash

## Idea

Finding duplicate images by hashing contents rather than comparing names or sizes. Names and timestamps change when files move between devices; the bytes do not. Grouping by hash reduces the comparison from every pair to one pass, which is what makes it usable on a whole photo library.

## Cost

O(n) hashes and O(n) memory, against O(n^2) pairwise comparisons.

## Where it is used

Deduplicating photos transferred from a phone.

## Source

[`media-manager/src/compare.py`](https://github.com/Ismael-Sallami/media-manager/blob/main/src/compare.py#L1-L117) &mdash; complete file.
