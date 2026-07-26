# Systems primitives

Structures that appear in any distributed service: probabilistic membership, rate limiting, and hashing that survives a change in the number of nodes.

2 implementations.

| Implementation | Language |
| --- | --- |
| [Bloom filter](bloom-filter/) | C++ |
| [Token bucket rate limiter and consistent hashing](rate-limiter-and-consistent-hashing/) | C++ |

Every file here was written for this repository and verifies itself; see [`patterns/`](../../patterns/) for the extracts from earlier work.

[Back to the catalogue](../../README.md)
