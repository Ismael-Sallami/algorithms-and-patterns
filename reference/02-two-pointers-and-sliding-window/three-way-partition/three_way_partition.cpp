// Pattern: Three way partition
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check three_way_partition.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

// Dutch national flag: sort an array of three distinct values in one pass.
//
// Three regions grow at once - below, equal, above - separated by three indices. The
// subtlety is that after swapping with the high region the element now at `mid` has
// not been examined, so `mid` must not advance; after swapping with the low region it
// has, so it must. Getting that wrong loses elements.
void three_way_partition(vector<int>& values, int pivot) {
  int low = 0, mid = 0, high = static_cast<int>(values.size()) - 1;
  while (mid <= high) {
    if (values[mid] < pivot) swap(values[low++], values[mid++]);
    else if (values[mid] > pivot) swap(values[mid], values[high--]);
    else ++mid;
  }
}

// Removes duplicates from a sorted array in place, returning the new length. A write
// pointer trailing a read pointer: the standard in-place compaction.
size_t deduplicate_sorted(vector<int>& values) {
  if (values.empty()) return 0;
  size_t write = 1;
  for (size_t read = 1; read < values.size(); ++read)
    if (values[read] != values[write - 1]) values[write++] = values[read];
  return write;
}

int main() {
  vector<int> flag = {2, 0, 2, 1, 1, 0};
  three_way_partition(flag, 1);
  assert(flag == vector<int>({0, 0, 1, 1, 2, 2}));

  vector<int> uniform = {1, 1, 1};
  three_way_partition(uniform, 1);
  assert(uniform == vector<int>({1, 1, 1}));

  vector<int> values = {1, 1, 2, 2, 2, 3};
  assert(deduplicate_sorted(values) == 3);
  assert(values[0] == 1 && values[1] == 2 && values[2] == 3);

  vector<int> none;
  assert(deduplicate_sorted(none) == 0);
  return 0;
}
