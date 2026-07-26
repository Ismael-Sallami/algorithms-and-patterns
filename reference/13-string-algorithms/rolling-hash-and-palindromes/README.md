# Rolling hash and palindromes

## Idea

Rabin-Karp: pattern matching by hashing.

A rolling hash updates in O(1) as the window slides - remove the leaving character's contribution, shift, add the entering one - so all n window hashes cost O(n) rather than O(n x m). A hash match is only evidence, not proof, so it is verified by comparison; with a large prime modulus collisions are rare enough that the expected cost stays O(n).

Against KMP, this loses the worst-case guarantee and gains the ability to compare arbitrary substrings in O(1) once the prefix hashes are built.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check rolling_hash_and_palindromes.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
