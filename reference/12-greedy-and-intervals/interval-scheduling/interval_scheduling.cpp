// Pattern: Interval scheduling
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check interval_scheduling.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <climits>
#include <vector>

using namespace std;

struct Interval {
  int start;
  int end;
  bool operator<(const Interval& other) const {
    return start != other.start ? start < other.start : end < other.end;
  }
};

// Greedy works when a local choice is provably safe - never worse than any alternative.
// For intervals, that choice is almost always driven by an end time, and which key you sort
// by is the entire algorithm.

// Most non-overlapping intervals: sort by end time, take each one that starts after the
// last taken finishes.
//
// The exchange argument: the interval finishing earliest leaves the most room for whatever
// follows, so any optimal solution can have its first interval swapped for that one without
// getting worse. Sorting by start time instead fails - one long interval starting first can
// block several short ones.
size_t max_non_overlapping(vector<Interval> intervals) {
  sort(intervals.begin(), intervals.end(),
       [](const Interval& a, const Interval& b) { return a.end < b.end; });
  size_t taken = 0;
  int last_end = INT_MIN;
  for (const Interval& interval : intervals) {
    if (interval.start < last_end) continue;
    ++taken;
    last_end = interval.end;
  }
  return taken;
}

// Merging overlapping intervals: sort by start, then extend or emit. Sorting by start is
// right here, because it is the only order in which overlaps are adjacent.
vector<Interval> merge_overlapping(vector<Interval> intervals) {
  if (intervals.empty()) return {};
  sort(intervals.begin(), intervals.end());
  vector<Interval> merged{intervals[0]};
  for (size_t i = 1; i < intervals.size(); ++i) {
    if (intervals[i].start <= merged.back().end)
      merged.back().end = max(merged.back().end, intervals[i].end);
    else
      merged.push_back(intervals[i]);
  }
  return merged;
}

// Maximum number of intervals overlapping at once - the rooms a schedule needs.
//
// A sweep line over the endpoints rather than over time: +1 at each start, -1 at each end,
// and the running total's maximum is the answer. Sorting ends before starts at the same
// coordinate is what makes a room free the instant it is vacated; the other order
// over-counts by one.
int max_concurrent(const vector<Interval>& intervals) {
  vector<pair<int, int>> events;  // (coordinate, delta)
  events.reserve(intervals.size() * 2);
  for (const Interval& interval : intervals) {
    events.push_back({interval.start, +1});
    events.push_back({interval.end, -1});
  }
  sort(events.begin(), events.end());  // -1 sorts before +1 at equal coordinates

  int running = 0, peak = 0;
  for (const auto& [coordinate, delta] : events) {
    running += delta;
    peak = max(peak, running);
  }
  return peak;
}

// Fewest arrows to burst all balloons: the same greedy as interval scheduling, read the
// other way round. One arrow at the earliest end point pierces every interval containing it.
size_t min_points_to_cover(vector<Interval> intervals) {
  if (intervals.empty()) return 0;
  sort(intervals.begin(), intervals.end(),
       [](const Interval& a, const Interval& b) { return a.end < b.end; });
  size_t arrows = 1;
  int last = intervals[0].end;
  for (const Interval& interval : intervals) {
    if (interval.start <= last) continue;
    ++arrows;
    last = interval.end;
  }
  return arrows;
}

int main() {
  const vector<Interval> meetings = {{1, 3}, {2, 4}, {3, 5}, {7, 8}};
  assert(max_non_overlapping(meetings) == 3);  // (1,3), (3,5), (7,8)
  assert(max_non_overlapping({}) == 0);
  assert(max_non_overlapping({{1, 10}}) == 1);
  // Sorting by start would take (1,10) and stop at 1; by end it takes all three.
  assert(max_non_overlapping({{1, 10}, {2, 3}, {4, 5}, {6, 7}}) == 3);

  vector<Interval> merged = merge_overlapping({{1, 3}, {2, 6}, {8, 10}, {15, 18}});
  assert(merged.size() == 3);
  assert(merged[0].start == 1 && merged[0].end == 6);
  // Touching intervals merge; disjoint ones do not.
  assert(merge_overlapping({{1, 2}, {2, 3}}).size() == 1);
  assert(merge_overlapping({{1, 2}, {3, 4}}).size() == 2);
  // A nested interval must not extend the outer one.
  vector<Interval> nested = merge_overlapping({{1, 10}, {2, 3}});
  assert(nested.size() == 1 && nested[0].end == 10);

  assert(max_concurrent({{1, 4}, {2, 5}, {3, 6}}) == 3);
  assert(max_concurrent({{1, 2}, {3, 4}}) == 1);
  // Ends sort before starts, so a room freed at 2 is reused at 2.
  assert(max_concurrent({{1, 2}, {2, 3}}) == 1);
  assert(max_concurrent({}) == 0);

  assert(min_points_to_cover({{10, 16}, {2, 8}, {1, 6}, {7, 12}}) == 2);
  assert(min_points_to_cover({{1, 2}, {3, 4}, {5, 6}}) == 3);
  assert(min_points_to_cover({}) == 0);
  return 0;
}
