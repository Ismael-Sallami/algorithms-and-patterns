// Pattern: Monotonic structures
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check monotonic_structures.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <deque>
#include <stack>
#include <vector>

using namespace std;

// A monotonic stack holds indices whose answer is still unknown, kept in sorted value
// order. An arriving element resolves every element it dominates at once. Each index is
// pushed once and popped once, so the total is O(n) even though the inner loop looks
// quadratic - that amortisation is the whole idea.

// Next strictly greater element to the right, or -1.
vector<int> next_greater(const vector<int>& values) {
  vector<int> answer(values.size(), -1);
  stack<int> pending;
  for (int i = 0; i < static_cast<int>(values.size()); ++i) {
    while (!pending.empty() && values[pending.top()] < values[i]) {
      answer[pending.top()] = values[i];
      pending.pop();
    }
    pending.push(i);
  }
  return answer;
}

// Largest rectangle in a histogram. A bar's rectangle extends until a strictly shorter bar
// on each side, and the monotonic stack finds both edges in one pass. The sentinel zero at
// the end forces the stack to drain without duplicating the closing logic.
long long largest_rectangle(vector<int> heights) {
  heights.push_back(0);
  stack<int> increasing;
  long long best = 0;
  for (int i = 0; i < static_cast<int>(heights.size()); ++i) {
    while (!increasing.empty() && heights[increasing.top()] >= heights[i]) {
      const int height = heights[increasing.top()];
      increasing.pop();
      const int left = increasing.empty() ? -1 : increasing.top();
      best = max(best, static_cast<long long>(height) * (i - left - 1));
    }
    increasing.push(i);
  }
  return best;
}

// Maximum of every window of k elements, in O(n).
//
// The deque holds indices whose values decrease from front to back, so the front is always
// the window maximum. An arriving element evicts everything smaller behind it, because
// those can never be the maximum again while it is in the window. A heap gives O(n log k);
// this gives O(n) with O(k) space.
vector<int> sliding_window_maximum(const vector<int>& values, int k) {
  vector<int> out;
  if (k <= 0 || static_cast<int>(values.size()) < k) return out;
  deque<int> decreasing;  // indices

  for (int i = 0; i < static_cast<int>(values.size()); ++i) {
    while (!decreasing.empty() && decreasing.front() <= i - k) decreasing.pop_front();
    while (!decreasing.empty() && values[decreasing.back()] <= values[i]) decreasing.pop_back();
    decreasing.push_back(i);
    if (i >= k - 1) out.push_back(values[decreasing.front()]);
  }
  return out;
}

// A stack that also reports its minimum in O(1). Scanning would be O(n) per query; a second
// stack keeping the minimum as of each push means popping restores the previous minimum for
// free. The cost is one extra value per element.
class MinStack {
  vector<int> values;
  vector<int> minima;  // minima[i] = min of values[0..i]

 public:
  void push(int value) {
    values.push_back(value);
    minima.push_back(minima.empty() ? value : min(minima.back(), value));
  }
  void pop() {
    values.pop_back();
    minima.pop_back();
  }
  int top() const { return values.back(); }
  int minimum() const { return minima.back(); }
  bool empty() const { return values.empty(); }
};

int main() {
  assert(next_greater({2, 1, 2, 4, 3}) == vector<int>({4, 2, 4, -1, -1}));
  assert(next_greater({5, 4, 3}) == vector<int>({-1, -1, -1}));
  // Equal neighbours are not "greater": the strict comparison matters.
  assert(next_greater({2, 2, 3}) == vector<int>({3, 3, -1}));

  assert(largest_rectangle({2, 1, 5, 6, 2, 3}) == 10);
  assert(largest_rectangle({2, 4}) == 4);
  assert(largest_rectangle({3, 3, 3}) == 9);

  assert(sliding_window_maximum({1, 3, -1, -3, 5, 3, 6, 7}, 3) ==
         vector<int>({3, 3, 5, 5, 6, 7}));
  assert(sliding_window_maximum({9, 8, 7}, 1) == vector<int>({9, 8, 7}));
  assert(sliding_window_maximum({4, 2, 12}, 3) == vector<int>({12}));
  // Equal values: eviction on <= keeps the deque from growing without bound.
  assert(sliding_window_maximum({2, 2, 2, 2}, 2) == vector<int>({2, 2, 2}));
  assert(sliding_window_maximum({1}, 5).empty());

  MinStack s;
  s.push(3); s.push(5);
  assert(s.minimum() == 3);
  s.push(2); s.push(1);
  assert(s.minimum() == 1);
  s.pop();
  assert(s.minimum() == 2);  // the previous minimum comes back
  s.pop();
  assert(s.minimum() == 3 && s.top() == 5);

  // Repeated minima must survive one pop each, not vanish together.
  MinStack r;
  r.push(2); r.push(2);
  r.pop();
  assert(r.minimum() == 2);
  return 0;
}
