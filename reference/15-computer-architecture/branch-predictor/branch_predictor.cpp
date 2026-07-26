// Pattern: Branch predictor
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check branch_predictor.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <vector>

using namespace std;

// Dynamic branch prediction.
//
// A pipelined processor must fetch the next instruction before the current branch has
// resolved, so it guesses. A wrong guess costs the whole pipeline refill - fifteen or
// twenty cycles on a deep pipeline - which is why a few percent of accuracy is worth
// real hardware.
//
// One-bit predictor: remember what the branch did last time. It mispredicts twice per
// loop, on entry and on exit, because a single bit flips on any surprise. For a tight
// inner loop that runs a few times, that is most of the branches.
//
// Two-bit saturating counter: the state must be wrong twice in a row before the
// prediction flips. That one change removes one of the two loop mispredictions, which
// is why two bits is the standard and three rarely pays for itself.
//
//   00 strongly not taken -> 01 weakly not taken -> 10 weakly taken -> 11 strongly taken
class OneBitPredictor {
  vector<uint8_t> table;
  long long correct = 0, wrong = 0;

 public:
  explicit OneBitPredictor(size_t entries) : table(entries, 0) {}
  bool predict(uint64_t address) const { return table[address % table.size()] != 0; }
  void update(uint64_t address, bool taken) {
    if (predict(address) == taken) ++correct; else ++wrong;
    table[address % table.size()] = taken ? 1 : 0;
  }
  double accuracy() const {
    const long long total = correct + wrong;
    return total == 0 ? 0.0 : static_cast<double>(correct) / static_cast<double>(total);
  }
  long long mispredictions() const { return wrong; }
};

class TwoBitPredictor {
  vector<uint8_t> table;  // 0..3
  long long correct = 0, wrong = 0;

 public:
  // Initialised weakly not taken, so a single taken branch does not flip it.
  explicit TwoBitPredictor(size_t entries) : table(entries, 1) {}
  bool predict(uint64_t address) const { return table[address % table.size()] >= 2; }
  void update(uint64_t address, bool taken) {
    if (predict(address) == taken) ++correct; else ++wrong;
    uint8_t& state = table[address % table.size()];
    if (taken) { if (state < 3) ++state; }
    else { if (state > 0) --state; }
  }
  double accuracy() const {
    const long long total = correct + wrong;
    return total == 0 ? 0.0 : static_cast<double>(correct) / static_cast<double>(total);
  }
  long long mispredictions() const { return wrong; }
};

// Cost of a mispredict in cycles per branch. This is what makes accuracy worth paying
// for: at a 20-cycle penalty, going from 90% to 95% saves a cycle per branch.
double cycles_per_branch(double misprediction_rate, int penalty_cycles) {
  return 1.0 + misprediction_rate * penalty_cycles;
}

// CPI with a memory stall term, the other half of the same calculation.
double effective_cpi(double base_cpi, double accesses_per_instruction,
                     double miss_rate, int miss_penalty) {
  return base_cpi + accesses_per_instruction * miss_rate * miss_penalty;
}

int main() {
  const uint64_t branch = 0x400100;

  // A loop taken 9 times then falling through, repeated 100 times: exactly the
  // pattern the two-bit counter is designed for.
  OneBitPredictor one_bit(1024);
  TwoBitPredictor two_bit(1024);
  for (int iteration = 0; iteration < 100; ++iteration) {
    for (int step = 0; step < 9; ++step) {
      one_bit.update(branch, true);
      two_bit.update(branch, true);
    }
    one_bit.update(branch, false);  // loop exit
    two_bit.update(branch, false);
  }
  // One bit mispredicts twice per loop, the exit and the re-entry. Two bits absorb
  // the exit, so only the re-entry costs.
  assert(one_bit.mispredictions() > two_bit.mispredictions());
  assert(two_bit.accuracy() > one_bit.accuracy());
  assert(two_bit.accuracy() > 0.88);

  TwoBitPredictor steady(16);
  for (int i = 0; i < 100; ++i) steady.update(branch, true);
  assert(steady.accuracy() > 0.97);

  // An alternating branch is the worst case: every one-bit prediction is wrong.
  OneBitPredictor alternating(16);
  for (int i = 0; i < 100; ++i) alternating.update(branch, i % 2 == 0);
  assert(alternating.accuracy() < 0.1);

  // A 20-cycle penalty at 5% mispredict costs two cycles per branch, not one.
  assert(cycles_per_branch(0.05, 20) == 2.0);
  assert(cycles_per_branch(0.0, 20) == 1.0);
  assert(effective_cpi(1.0, 1.5, 0.02, 100) == 4.0);
  return 0;
}
