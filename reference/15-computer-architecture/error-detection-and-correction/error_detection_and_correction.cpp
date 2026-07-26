// Pattern: Error detection and correction
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check error_detection_and_correction.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <vector>

using namespace std;

// Detecting and correcting bit errors in stored or transmitted data.
//
// Parity detects any single-bit error and cannot locate it, so it can only ask for a
// retransmission. Hamming codes locate it, which is what ECC memory needs: there is
// nobody to ask for a resend.
//
// The Hamming trick is placing check bits at power-of-two positions. The check bit at
// position 2^k covers every position whose bit k is set, so the failing check bits
// spell the position of the error in binary. Syndrome 0 means clean; syndrome 5 means
// bit 5 flipped.
//
// Hamming(7,4) corrects one error in seven bits and cannot tell a double error from a
// single one. Adding an overall parity bit - SECDED, what real ECC DIMMs use - makes
// double errors distinguishable, and so reportable rather than silently miscorrected.
using Bits = vector<int>;

// Encodes 4 data bits into 7, with parity at positions 1, 2 and 4 (1-indexed).
Bits hamming_encode(const Bits& data) {
  Bits code(8, 0);  // index 0 unused so the positions match the arithmetic
  code[3] = data[0];
  code[5] = data[1];
  code[6] = data[2];
  code[7] = data[3];
  code[1] = code[3] ^ code[5] ^ code[7];  // positions with bit 0 set
  code[2] = code[3] ^ code[6] ^ code[7];  // bit 1 set
  code[4] = code[5] ^ code[6] ^ code[7];  // bit 2 set
  return code;
}

// Returns the 1-indexed position of the flipped bit, or 0 when the word is clean.
int hamming_syndrome(const Bits& code) {
  const int p1 = code[1] ^ code[3] ^ code[5] ^ code[7];
  const int p2 = code[2] ^ code[3] ^ code[6] ^ code[7];
  const int p4 = code[4] ^ code[5] ^ code[6] ^ code[7];
  return p1 * 1 + p2 * 2 + p4 * 4;  // the failing checks spell the position
}

Bits hamming_correct(Bits code) {
  const int position = hamming_syndrome(code);
  if (position != 0 && position < static_cast<int>(code.size())) code[position] ^= 1;
  return code;
}

Bits hamming_decode(const Bits& code) { return {code[3], code[5], code[6], code[7]}; }

// CRC-32, the checksum used by Ethernet, zip and PNG. Polynomial division over GF(2),
// where subtraction is XOR, so the whole thing is shifts and XORs. It detects every
// burst error shorter than 33 bits, which is the failure mode a serial link actually
// produces - unlike a sum, which misses reordered or compensating errors.
uint32_t crc32(const vector<uint8_t>& data) {
  uint32_t remainder = 0xFFFFFFFF;  // non-zero init, so leading zeros still register
  for (uint8_t byte : data) {
    remainder ^= byte;
    for (int bit = 0; bit < 8; ++bit)
      remainder = (remainder >> 1) ^ (0xEDB88320u & (~(remainder & 1) + 1));
  }
  return ~remainder;
}

// Even parity over a word: one bit, detects any odd number of flips, misses every even
// number.
int parity_of(uint32_t value) { return __builtin_popcount(value) & 1; }

int main() {
  const Bits data = {1, 0, 1, 1};
  Bits code = hamming_encode(data);
  assert(hamming_syndrome(code) == 0);
  assert(hamming_decode(code) == data);

  // Every single-bit flip in every position must be located and corrected.
  for (int position = 1; position <= 7; ++position) {
    Bits damaged = code;
    damaged[position] ^= 1;
    assert(hamming_syndrome(damaged) == position);
    assert(hamming_decode(hamming_correct(damaged)) == data);
  }

  // A double error is where Hamming(7,4) gives up: the syndrome is non-zero so
  // something is detected, but the correction makes it worse. This is exactly the
  // reason production ECC adds the extra parity bit.
  Bits doubly_damaged = code;
  doubly_damaged[1] ^= 1;
  doubly_damaged[2] ^= 1;
  assert(hamming_syndrome(doubly_damaged) != 0);
  assert(hamming_decode(hamming_correct(doubly_damaged)) != data);

  // CRC-32 against the standard check value for "123456789".
  const vector<uint8_t> digits = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
  assert(crc32(digits) == 0xCBF43926u);
  assert(crc32({}) == 0);

  vector<uint8_t> altered = digits;
  altered[0] ^= 1;
  assert(crc32(altered) != crc32(digits));

  // Reordering changes it too, where a plain sum would not notice.
  vector<uint8_t> swapped = digits;
  swap(swapped[0], swapped[1]);
  assert(crc32(swapped) != crc32(digits));

  assert(parity_of(0b0000) == 0);
  assert(parity_of(0b0001) == 1);
  assert(parity_of(0b0011) == 0);  // two flips look clean: parity's blind spot
  return 0;
}
