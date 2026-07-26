// Pattern: Difference array
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check difference_array.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

// Many range updates followed by reads. Applying each update directly costs
// O(range); recording only the boundaries costs O(1) per update and one O(n) pass to
// materialise the result.
//
// Adding delta to [from, to] means +delta at from and -delta just past to. A prefix
// sum over those marks reproduces every update at once.
class DifferenceArray {
  vector<long long> marks;

 public:
  explicit DifferenceArray(size_t size) : marks(size + 1, 0) {}

  void add_to_range(size_t from, size_t to, long long delta) {
    assert(from <= to && to + 1 < marks.size());
    marks[from] += delta;
    marks[to + 1] -= delta;
  }

  vector<long long> materialise() const {
    vector<long long> out(marks.size() - 1, 0);
    long long running = 0;
    for (size_t i = 0; i + 1 < marks.size(); ++i) {
      running += marks[i];
      out[i] = running;
    }
    return out;
  }
};

int main() {
  DifferenceArray flights(5);
  flights.add_to_range(0, 1, 10);
  flights.add_to_range(1, 3, 20);
  flights.add_to_range(2, 4, 30);
  assert(flights.materialise() == vector<long long>({10, 30, 50, 50, 30}));

  // Overlapping and negative updates on the same cell accumulate.
  DifferenceArray d(3);
  d.add_to_range(0, 2, 5);
  d.add_to_range(1, 1, -5);
  assert(d.materialise() == vector<long long>({5, 0, 5}));
  return 0;
}
