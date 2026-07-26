// Pattern: Dijkstra's algorithm
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check dijkstra.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

struct Edge { int to; long long weight; };
using Graph = vector<vector<Edge>>;
constexpr long long kUnreachable = LLONG_MAX;

// Dijkstra over an adjacency list with a binary heap.
//
// The correctness argument: when a vertex is popped, no shorter route to it can still be
// found, because any such route would pass through an unpopped vertex whose distance is
// already at least as large. That argument needs non-negative weights, which is the
// algorithm's one hard requirement.
//
// This is the lazy variant: instead of decreasing a key in place, a better distance is
// pushed as a new entry and stale entries are skipped on pop. The heap can hold up to E
// entries rather than V, but it needs no indexed heap and the bound stays O(E log V).
vector<long long> shortest_distances(const Graph& graph, int source) {
  vector<long long> distance(graph.size(), kUnreachable);
  using Entry = pair<long long, int>;  // (distance, vertex)
  priority_queue<Entry, vector<Entry>, greater<Entry>> frontier;
  distance[source] = 0;
  frontier.push({0, source});

  while (!frontier.empty()) {
    const auto [d, current] = frontier.top();
    frontier.pop();
    if (d > distance[current]) continue;  // stale entry, already improved on
    for (const Edge& edge : graph[current]) {
      const long long candidate = d + edge.weight;
      if (candidate >= distance[edge.to]) continue;
      distance[edge.to] = candidate;
      frontier.push({candidate, edge.to});
    }
  }
  return distance;
}

// With the predecessor recorded on improvement, the path itself comes back rather than
// just its length.
vector<int> shortest_path(const Graph& graph, int source, int target) {
  vector<long long> distance(graph.size(), kUnreachable);
  vector<int> parent(graph.size(), -1);
  using Entry = pair<long long, int>;
  priority_queue<Entry, vector<Entry>, greater<Entry>> frontier;
  distance[source] = 0;
  frontier.push({0, source});

  while (!frontier.empty()) {
    const auto [d, current] = frontier.top();
    frontier.pop();
    if (d > distance[current]) continue;
    for (const Edge& edge : graph[current]) {
      const long long candidate = d + edge.weight;
      if (candidate >= distance[edge.to]) continue;
      distance[edge.to] = candidate;
      parent[edge.to] = current;
      frontier.push({candidate, edge.to});
    }
  }
  if (distance[target] == kUnreachable) return {};
  vector<int> path;
  for (int at = target; at != -1; at = parent[at]) path.push_back(at);
  reverse(path.begin(), path.end());
  return path;
}

int main() {
  Graph graph(5);
  graph[0] = {{1, 4}, {2, 1}};
  graph[1] = {{3, 1}};
  graph[2] = {{1, 2}, {3, 5}};

  vector<long long> distance = shortest_distances(graph, 0);
  assert(distance[0] == 0);
  assert(distance[2] == 1);
  assert(distance[1] == 3);  // 0->2->1 costs 3, beating the direct edge of 4
  assert(distance[3] == 4);
  assert(distance[4] == kUnreachable);

  assert(shortest_path(graph, 0, 3) == vector<int>({0, 2, 1, 3}));
  assert(shortest_path(graph, 0, 4).empty());
  assert(shortest_path(graph, 0, 0) == vector<int>({0}));

  // Zero-weight edges are allowed; only negative ones break the argument.
  Graph zeros(3);
  zeros[0] = {{1, 0}};
  zeros[1] = {{2, 0}};
  assert(shortest_distances(zeros, 0)[2] == 0);

  // Parallel edges: the cheaper one must win.
  Graph parallel(2);
  parallel[0] = {{1, 9}, {1, 2}};
  assert(shortest_distances(parallel, 0)[1] == 2);
  return 0;
}
