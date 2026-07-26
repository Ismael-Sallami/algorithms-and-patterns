// Pattern: Bipartite check
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check bipartite_check.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

using namespace std;

using Graph = vector<vector<int>>;

// A graph is bipartite when its vertices split into two sets with no edge inside
// either. Equivalently it is two-colourable, and equivalently it has no odd cycle -
// which is what the traversal actually detects.
//
// BFS assigns the opposite colour to each neighbour. A conflict means an edge between
// same-coloured vertices, which closes a cycle of odd length. The outer loop matters: a
// disconnected graph is bipartite only if every component is.
bool is_bipartite(const Graph& graph) {
  vector<int> colour(graph.size(), -1);
  for (size_t start = 0; start < graph.size(); ++start) {
    if (colour[start] != -1) continue;
    colour[start] = 0;
    queue<int> frontier;
    frontier.push(static_cast<int>(start));
    while (!frontier.empty()) {
      const int current = frontier.front();
      frontier.pop();
      for (int next : graph[current]) {
        if (colour[next] == colour[current]) return false;
        if (colour[next] != -1) continue;
        colour[next] = 1 - colour[current];
        frontier.push(next);
      }
    }
  }
  return true;
}

// The colouring itself, when one exists. Usually the partition is what the caller
// wanted, not the yes/no answer.
pair<vector<int>, vector<int>> bipartition(const Graph& graph) {
  vector<int> colour(graph.size(), -1);
  for (size_t start = 0; start < graph.size(); ++start) {
    if (colour[start] != -1) continue;
    colour[start] = 0;
    queue<int> frontier;
    frontier.push(static_cast<int>(start));
    while (!frontier.empty()) {
      const int current = frontier.front();
      frontier.pop();
      for (int next : graph[current]) {
        if (colour[next] == colour[current]) return {{}, {}};
        if (colour[next] != -1) continue;
        colour[next] = 1 - colour[current];
        frontier.push(next);
      }
    }
  }
  pair<vector<int>, vector<int>> sides;
  for (size_t v = 0; v < graph.size(); ++v)
    (colour[v] == 0 ? sides.first : sides.second).push_back(static_cast<int>(v));
  return sides;
}

int main() {
  auto connect = [](Graph& g, int a, int b) { g[a].push_back(b); g[b].push_back(a); };

  // A four-cycle: even, so bipartite.
  Graph even(4);
  connect(even, 0, 1); connect(even, 1, 2); connect(even, 2, 3); connect(even, 3, 0);
  assert(is_bipartite(even));
  auto [left, right] = bipartition(even);
  assert(left == vector<int>({0, 2}));
  assert(right == vector<int>({1, 3}));

  // A triangle: odd cycle, so not bipartite.
  Graph odd(3);
  connect(odd, 0, 1); connect(odd, 1, 2); connect(odd, 2, 0);
  assert(!is_bipartite(odd));
  assert(bipartition(odd).first.empty());

  // Disconnected: every component must be bipartite. Here one is not.
  Graph mixed(6);
  connect(mixed, 0, 1);
  connect(mixed, 3, 4); connect(mixed, 4, 5); connect(mixed, 5, 3);
  assert(!is_bipartite(mixed));

  Graph isolated(3);  // no edges at all
  assert(is_bipartite(isolated));
  return 0;
}
