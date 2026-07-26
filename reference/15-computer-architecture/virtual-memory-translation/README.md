# Virtual memory translation

## Idea

Virtual to physical translation through a two-level page table, with a TLB.

A single-level table for a 32-bit space with 4 KiB pages needs 2^20 entries per process, allocated whether or not the process uses that memory. Splitting the page number in two lets second-level tables exist only where pages are actually mapped: a process touching 1 MiB pays for one second-level table, not for a million entries.

| level-1 index (10) | level-2 index (10) | page offset (12) |

The cost is that every access now needs two memory reads before the real one. The TLB makes that affordable - a small fully-associative cache of recent translations, with hit rates typically above 99% because page locality is even stronger than data locality.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check virtual_memory_translation.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
