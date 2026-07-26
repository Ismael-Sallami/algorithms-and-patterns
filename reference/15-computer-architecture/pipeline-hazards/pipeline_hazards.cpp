// Pattern: Pipeline hazards
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check pipeline_hazards.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

// Data hazards in a five-stage pipeline, and what forwarding does about them.
//
//   IF fetch, ID decode and register read, EX execute, MEM memory, WB write back
//
// The hazard is a timing mismatch: an instruction reads its registers in ID, but the
// producer only writes them in WB, three stages later. Without help a dependent
// instruction waits.
//
// Forwarding routes the value from where it already exists - the EX or MEM output -
// straight to the next instruction's EX input, so most dependencies cost nothing.
//
// The exception is the load-use hazard. A load produces its value in MEM and the
// consumer needs it in EX, one cycle earlier. No wiring fixes that: the value does not
// exist yet. One stall is unavoidable, which is why compilers reorder instructions to
// put something useful between a load and its use.
struct Instruction {
  string operation;  // "add", "lw", "sw", "beq"
  int destination;   // written register, -1 if none
  int source_a;
  int source_b;
};

bool writes_register(const Instruction& i) {
  return i.destination >= 0 && i.operation != "sw" && i.operation != "beq";
}
bool is_load(const Instruction& i) { return i.operation == "lw"; }
bool reads(const Instruction& i, int reg) {
  return reg >= 0 && (i.source_a == reg || i.source_b == reg);
}

// Stalls with no forwarding. A producer's value is safe to read only once written
// back, so a consumer one instruction later waits two cycles and two later waits one.
int stalls_without_forwarding(const vector<Instruction>& program) {
  int stalls = 0;
  for (size_t i = 1; i < program.size(); ++i)
    for (size_t distance = 1; distance <= 2 && distance <= i; ++distance) {
      const Instruction& producer = program[i - distance];
      if (!writes_register(producer)) continue;
      if (!reads(program[i], producer.destination)) continue;
      stalls += static_cast<int>(3 - distance);
      break;  // the nearest dependency dominates
    }
  return stalls;
}

// Stalls with full forwarding. Only the load-use case remains, and only when the
// consumer immediately follows the load.
int stalls_with_forwarding(const vector<Instruction>& program) {
  int stalls = 0;
  for (size_t i = 1; i < program.size(); ++i) {
    const Instruction& producer = program[i - 1];
    if (!is_load(producer) || !writes_register(producer)) continue;
    if (reads(program[i], producer.destination)) ++stalls;
  }
  return stalls;
}

// Total cycles for a k-stage pipeline running n instructions plus stalls. The pipeline
// fills once, then retires one instruction per cycle.
int total_cycles(size_t instructions, int stages, int stalls) {
  return static_cast<int>(instructions) + stages - 1 + stalls;
}

int main() {
  // add r1, r2, r3 then sub r4, r1, r5: forwarding covers the dependency.
  vector<Instruction> arithmetic = {{"add", 1, 2, 3}, {"sub", 4, 1, 5}};
  assert(stalls_without_forwarding(arithmetic) == 2);
  assert(stalls_with_forwarding(arithmetic) == 0);

  // lw r1, 0(r2) then add r3, r1, r4: one stall survives forwarding.
  vector<Instruction> load_use = {{"lw", 1, 2, -1}, {"add", 3, 1, 4}};
  assert(stalls_with_forwarding(load_use) == 1);

  // The same load with an independent instruction moved in between - the reordering a
  // compiler performs - removes the stall entirely.
  vector<Instruction> scheduled = {
      {"lw", 1, 2, -1}, {"add", 6, 7, 8}, {"add", 3, 1, 4}};
  assert(stalls_with_forwarding(scheduled) == 0);

  vector<Instruction> independent = {
      {"add", 1, 2, 3}, {"add", 4, 5, 6}, {"add", 7, 8, 9}};
  assert(stalls_without_forwarding(independent) == 0);
  assert(stalls_with_forwarding(independent) == 0);

  // A store reads its data register but writes nothing: a consumer, never a producer.
  vector<Instruction> store = {{"lw", 1, 2, -1}, {"sw", -1, 1, 3}};
  assert(stalls_with_forwarding(store) == 1);

  // Ideal throughput: 5 instructions through 5 stages take 9 cycles, not 25.
  assert(total_cycles(5, 5, 0) == 9);
  assert(total_cycles(5, 5, 2) == 11);
  // One instruction sees no benefit from pipelining at all.
  assert(total_cycles(1, 5, 0) == 5);
  return 0;
}
