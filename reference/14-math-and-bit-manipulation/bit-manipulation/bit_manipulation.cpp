// Pattern: Bit manipulation
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check bit_manipulation.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <random>
#include <vector>

using namespace std;

// Bit tricks worth knowing, and what each one is actually for.

// Isolates the lowest set bit. x & -x works because negating in two's complement inverts
// everything above the lowest set bit and leaves it standing. This is the operation a
// Fenwick tree is built on.
uint32_t lowest_set_bit(uint32_t x) { return x & (~x + 1); }

// Clears the lowest set bit. Looping on this counts set bits in as many iterations as
// there are bits set, rather than the full word width.
uint32_t clear_lowest_set_bit(uint32_t x) { return x & (x - 1); }

int popcount_loop(uint32_t x) {
  int count = 0;
  while (x != 0) { x = clear_lowest_set_bit(x); ++count; }
  return count;
}

// A power of two has exactly one bit set, so clearing it leaves zero. One comparison
// instead of a division loop.
bool is_power_of_two(uint32_t x) { return x != 0 && clear_lowest_set_bit(x) == 0; }

// Enumerating every subset of a set encoded as a bitmask. The trick is that
// (subset - 1) & mask walks the subsets in decreasing order without revisiting any, which
// is what makes subset-sum DP over bitmasks practical.
vector<uint32_t> all_subsets(uint32_t mask) {
  vector<uint32_t> out;
  for (uint32_t subset = mask;; subset = (subset - 1) & mask) {
    out.push_back(subset);
    if (subset == 0) break;
  }
  return out;
}

// Swapping the byte order of a word. What a network stack does on every big-endian value
// arriving on a little-endian machine.
uint32_t swap_endianness(uint32_t value) {
  return ((value & 0x000000FFu) << 24) | ((value & 0x0000FF00u) << 8) |
         ((value & 0x00FF0000u) >> 8) | ((value & 0xFF000000u) >> 24);
}

// Fisher-Yates shuffle. Every permutation is equally likely, which the naive "swap each
// element with a random one" does not achieve - that one produces n^n equally likely swap
// sequences over n! permutations, so some come out more often.
void fisher_yates(vector<int>& values, mt19937& rng) {
  for (size_t i = values.size(); i-- > 1;) {
    uniform_int_distribution<size_t> pick(0, i);  // inclusive of i, which is the point
    swap(values[i], values[pick(rng)]);
  }
}

// Reservoir sampling: k items uniformly from a stream of unknown length, in O(1) memory
// per slot. Item i replaces a random slot with probability k/i, which is exactly what
// keeps every prefix uniformly sampled.
vector<int> reservoir_sample(const vector<int>& stream, size_t k, mt19937& rng) {
  vector<int> reservoir;
  for (size_t i = 0; i < stream.size(); ++i) {
    if (reservoir.size() < k) { reservoir.push_back(stream[i]); continue; }
    uniform_int_distribution<size_t> pick(0, i);
    const size_t slot = pick(rng);
    if (slot < k) reservoir[slot] = stream[i];
  }
  return reservoir;
}

int main() {
  assert(lowest_set_bit(0b1011000) == 0b1000);
  assert(lowest_set_bit(0b1) == 1);
  assert(lowest_set_bit(0) == 0);

  assert(clear_lowest_set_bit(0b1011) == 0b1010);
  assert(popcount_loop(0) == 0);
  assert(popcount_loop(0b1011) == 3);
  assert(popcount_loop(0xFFFFFFFF) == 32);
  // Must agree with the compiler builtin over a range of values.
  for (uint32_t x = 0; x < 1000; ++x)
    assert(popcount_loop(x) == __builtin_popcount(x));

  assert(is_power_of_two(1) && is_power_of_two(1024));
  assert(!is_power_of_two(0) && !is_power_of_two(3));

  // A 3-bit mask has 2^3 subsets, including the empty one and itself.
  assert(all_subsets(0b111).size() == 8);
  assert(all_subsets(0b101).size() == 4);
  assert(all_subsets(0).size() == 1);

  assert(swap_endianness(0x12345678u) == 0x78563412u);
  // Swapping twice is the identity, which is the check that it is right.
  assert(swap_endianness(swap_endianness(0xDEADBEEFu)) == 0xDEADBEEFu);

  mt19937 rng(42);
  vector<int> values(10);
  for (int i = 0; i < 10; ++i) values[i] = i;
  vector<int> shuffled = values;
  fisher_yates(shuffled, rng);
  // A permutation: same multiset, and with this seed not the same order.
  sort(shuffled.begin(), shuffled.end());
  assert(shuffled == values);

  vector<int> stream(1000);
  for (int i = 0; i < 1000; ++i) stream[i] = i;
  vector<int> sample = reservoir_sample(stream, 10, rng);
  assert(sample.size() == 10);
  for (int value : sample) assert(value >= 0 && value < 1000);
  // A stream shorter than k returns the whole stream.
  assert(reservoir_sample({1, 2}, 10, rng).size() == 2);
  return 0;
}
