# Number theory

## Idea

Sieve of Eratosthenes. Every composite is crossed off by its smallest prime factor, so the total work is the harmonic sum over primes - O(n log log n), close enough to linear to be the right answer for any bounded range.

Two details matter: the outer loop stops at sqrt(n), because a composite below n must have a factor below sqrt(n); and the inner loop starts at p*p, because smaller multiples of p were already crossed off by smaller primes.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check number_theory.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
