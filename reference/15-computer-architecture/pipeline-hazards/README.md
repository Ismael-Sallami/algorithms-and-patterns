# Pipeline hazards

## Idea

Data hazards in a five-stage pipeline, and what forwarding does about them.

IF fetch, ID decode and register read, EX execute, MEM memory, WB write back

The hazard is a timing mismatch: an instruction reads its registers in ID, but the producer only writes them in WB, three stages later. Without help a dependent instruction waits.

Forwarding routes the value from where it already exists - the EX or MEM output - straight to the next instruction's EX input, so most dependencies cost nothing.

The exception is the load-use hazard. A load produces its value in MEM and the consumer needs it in EX, one cycle earlier. No wiring fixes that: the value does not exist yet. One stall is unavoidable, which is why compilers reorder instructions to put something useful between a load and its use.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check pipeline_hazards.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
