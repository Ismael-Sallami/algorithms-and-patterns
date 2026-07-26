// Pattern: Bellman-Ford
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check bellman_ford.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <climits>
#include <vector>

using namespace std;

struct Edge { int from; int to; long long weight; };
constexpr long long kUnreachable = LLONG_MAX;

// Bellman-Ford: shortest paths with negative weights allowed.
//
// Dijkstra's argument fails once an edge can be negative, because a longer route may
// still improve later. Bellman-Ford gives that up and relaxes every edge V-1 times.
// That is enough because a shortest path visits at most V vertices, so it has at most
// V-1 edges, and pass i settles every path of i edges.
//
// The cost is O(V x E) against Dijkstra's O(E log V). What it buys is negative weights
// and, more usefully, detection of negative cycles: if a V-th pass still improves
// something, no shortest path exists at all.
struct Result {
  vector<long long> distance;
  bool has_negative_cycle = false;
};

Result bellman_ford(size_t vertices, const vector<Edge>& edges, int source) {
  Result result;
  result.distance.assign(vertices, kUnreachable);
  result.distance[source] = 0;

  for (size_t pass = 0; pass + 1 < vertices; ++pass) {
    bool improved = false;
    for (const Edge& edge : edges) {
      if (result.distance[edge.from] == kUnreachable) continue;
      const long long candidate = result.distance[edge.from] + edge.weight;
      if (candidate < result.distance[edge.to]) {
        result.distance[edge.to] = candidate;
        improved = true;
      }
    }
    if (!improved) break;  // settled early; common on well-behaved graphs
  }

  // One extra pass. Any further improvement can only come from a cycle of negative
  // total weight, which makes the shortest path undefined.
  for (const Edge& edge : edges) {
    if (result.distance[edge.from] == kUnreachable) continue;
    if (result.distance[edge.from] + edge.weight < result.distance[edge.to]) {
      result.has_negative_cycle = true;
      break;
    }
  }
  return result;
}

int main() {
  // 0->1 (4), 0->2 (5), 1->2 (-3). The route 0->1->2 costs 1, less than the direct 5,
  // which is the case Dijkstra would get wrong.
  vector<Edge> edges = {{0, 1, 4}, {0, 2, 5}, {1, 2, -3}};
  Result result = bellman_ford(3, edges, 0);
  assert(!result.has_negative_cycle);
  assert(result.distance[1] == 4);
  assert(result.distance[2] == 1);

  // Unreachable vertices stay unreachable and must not be relaxed through.
  assert(bellman_ford(4, edges, 0).distance[3] == kUnreachable);

  // A negative cycle: 1->2 (-3) and 2->1 (1) sum to -2 and can be looped.
  vector<Edge> cyclic = {{0, 1, 1}, {1, 2, -3}, {2, 1, 1}};
  assert(bellman_ford(3, cyclic, 0).has_negative_cycle);

  // A negative edge that is not part of a cycle is fine.
  Result descending = bellman_ford(3, {{0, 1, -1}, {1, 2, -1}}, 0);
  assert(!descending.has_negative_cycle);
  assert(descending.distance[2] == -2);

  // A negative cycle unreachable from the source must not be reported: no shortest
  // path through it is being claimed.
  vector<Edge> detached = {{0, 1, 1}, {2, 3, -5}, {3, 2, 1}};
  assert(!bellman_ford(4, detached, 0).has_negative_cycle);
  return 0;
}
