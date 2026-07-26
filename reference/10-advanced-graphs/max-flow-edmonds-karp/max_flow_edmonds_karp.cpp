// Pattern: Maximum flow by Edmonds-Karp
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check max_flow_edmonds_karp.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

// Maximum flow from source to sink.
//
// The Ford-Fulkerson idea is to repeatedly push flow along any path with spare capacity.
// What makes it correct is the residual graph: sending f units along an edge also creates
// a reverse edge of capacity f, so a later augmenting path can undo an earlier bad
// choice. Without those back edges a greedy first path can block the optimum permanently.
//
// Edmonds-Karp is Ford-Fulkerson with BFS, so each augmenting path is the shortest
// available. That choice bounds the number of augmentations at O(V x E) regardless of the
// capacities, giving O(V x E^2) overall. With DFS instead, the running time depends on the
// capacity values.
class MaxFlow {
  size_t n;
  vector<vector<long long>> capacity;  // residual capacity
  vector<vector<int>> adjacency;       // both directions, so back edges are reachable

 public:
  explicit MaxFlow(size_t vertices)
      : n(vertices), capacity(vertices, vector<long long>(vertices, 0)), adjacency(vertices) {}

  void add_edge(int from, int to, long long units) {
    if (capacity[from][to] == 0 && capacity[to][from] == 0) {
      adjacency[from].push_back(to);
      adjacency[to].push_back(from);  // the residual edge must be traversable
    }
    capacity[from][to] += units;      // parallel edges accumulate
  }

  long long run(int source, int sink) {
    long long total = 0;
    for (;;) {
      vector<int> parent(n, -1);
      parent[source] = source;
      queue<int> frontier;
      frontier.push(source);

      while (!frontier.empty() && parent[sink] == -1) {
        const int current = frontier.front();
        frontier.pop();
        for (int next : adjacency[current]) {
          if (parent[next] != -1 || capacity[current][next] <= 0) continue;
          parent[next] = current;
          frontier.push(next);
        }
      }
      if (parent[sink] == -1) break;  // no augmenting path: the flow is maximum

      long long bottleneck = LLONG_MAX;
      for (int at = sink; at != source; at = parent[at])
        bottleneck = min(bottleneck, capacity[parent[at]][at]);
      for (int at = sink; at != source; at = parent[at]) {
        capacity[parent[at]][at] -= bottleneck;
        capacity[at][parent[at]] += bottleneck;  // create or grow the back edge
      }
      total += bottleneck;
    }
    return total;
  }

  // The minimum cut, which equals the maximum flow. After saturation the vertices still
  // reachable from the source in the residual graph are exactly one side of it - the
  // max-flow min-cut theorem made constructive.
  vector<int> source_side(int source) {
    vector<bool> reachable(n, false);
    queue<int> frontier;
    reachable[source] = true;
    frontier.push(source);
    while (!frontier.empty()) {
      const int current = frontier.front();
      frontier.pop();
      for (int next : adjacency[current]) {
        if (reachable[next] || capacity[current][next] <= 0) continue;
        reachable[next] = true;
        frontier.push(next);
      }
    }
    vector<int> side;
    for (size_t v = 0; v < n; ++v)
      if (reachable[v]) side.push_back(static_cast<int>(v));
    return side;
  }
};

// Maximum bipartite matching reduces to max flow: a unit-capacity source into the left
// side, the given edges across, a unit-capacity sink out of the right. Unit capacities
// force each vertex into at most one pair.
int maximum_matching(int left_count, int right_count, const vector<pair<int, int>>& allowed) {
  const int source = left_count + right_count;
  const int sink = source + 1;
  MaxFlow network(static_cast<size_t>(sink) + 1);
  for (int l = 0; l < left_count; ++l) network.add_edge(source, l, 1);
  for (int r = 0; r < right_count; ++r) network.add_edge(left_count + r, sink, 1);
  for (const auto& [l, r] : allowed) network.add_edge(l, left_count + r, 1);
  return static_cast<int>(network.run(source, sink));
}

int main() {
  // The standard example: maximum flow 23 from 0 to 5.
  MaxFlow network(6);
  network.add_edge(0, 1, 16); network.add_edge(0, 2, 13);
  network.add_edge(1, 2, 10); network.add_edge(2, 1, 4);
  network.add_edge(1, 3, 12); network.add_edge(3, 2, 9);
  network.add_edge(2, 4, 14); network.add_edge(4, 3, 7);
  network.add_edge(3, 5, 20); network.add_edge(4, 5, 4);
  assert(network.run(0, 5) == 23);

  // A single bottleneck caps the whole network, and the cut is {0, 1}.
  MaxFlow narrow(4);
  narrow.add_edge(0, 1, 100);
  narrow.add_edge(1, 2, 1);
  narrow.add_edge(2, 3, 100);
  assert(narrow.run(0, 3) == 1);
  assert(narrow.source_side(0) == vector<int>({0, 1}));

  MaxFlow split(3);
  split.add_edge(0, 1, 5);
  assert(split.run(0, 2) == 0);  // no path at all

  // Parallel edges accumulate rather than overwrite.
  MaxFlow doubled(2);
  doubled.add_edge(0, 1, 3);
  doubled.add_edge(0, 1, 4);
  assert(doubled.run(0, 1) == 7);

  assert(maximum_matching(3, 3, {{0, 0}, {0, 1}, {1, 1}, {2, 2}}) == 3);
  // Two left vertices competing for one right vertex: only one can be matched.
  assert(maximum_matching(2, 1, {{0, 0}, {1, 0}}) == 1);
  return 0;
}
