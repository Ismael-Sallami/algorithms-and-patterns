# Error detection and correction

## Idea

Detecting and correcting bit errors in stored or transmitted data.

Parity detects any single-bit error and cannot locate it, so it can only ask for a retransmission. Hamming codes locate it, which is what ECC memory needs: there is nobody to ask for a resend.

The Hamming trick is placing check bits at power-of-two positions. The check bit at position 2^k covers every position whose bit k is set, so the failing check bits spell the position of the error in binary. Syndrome 0 means clean; syndrome 5 means bit 5 flipped.

Hamming(7,4) corrects one error in seven bits and cannot tell a double error from a single one. Adding an overall parity bit - SECDED, what real ECC DIMMs use - makes double errors distinguishable, and so reportable rather than silently miscorrected.

## Verification

Self-contained and self-testing. The assertions cover the edge cases the explanation above calls out.

```
g++ -std=c++20 -O1 -Wall -o /tmp/check error_detection_and_correction.cpp && /tmp/check
```

## Provenance

Written for this repository. Unlike the files under [`patterns/`](../../../patterns/), which are extracts from my earlier coursework and projects and link back to them, this one has no prior commit history behind it.
