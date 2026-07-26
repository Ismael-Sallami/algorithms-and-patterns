// Pattern: Depth first search and cycles
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check depth_first_search_and_cycles.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

using Graph = vector<vector<int>>;

// DFS with an explicit stack rather than recursion, so the depth is bounded by heap
// memory instead of the call stack. On a graph with a long path the recursive form
// overflows.
vector<int> dfs_order(const Graph& graph, int source) {
  vector<int> order;
  vector<bool> seen(graph.size(), false);
  vector<int> stack{source};

  while (!stack.empty()) {
    const int current = stack.back();
    stack.pop_back();
    if (seen[current]) continue;  // may have been pushed more than once
    seen[current] = true;
    order.push_back(current);
    // Pushed in reverse so the smallest neighbour is visited first.
    for (size_t i = graph[current].size(); i-- > 0;)
      if (!seen[graph[current][i]]) stack.push_back(graph[current][i]);
  }
  return order;
}

// Cycle detection in a directed graph needs three states, not two. A vertex already
// finished is not evidence of a cycle - only one still on the current path is. Two
// states cannot tell those apart, and report a diamond as a cycle.
enum class Colour { White, Grey, Black };  // unvisited, on the path, finished

static bool has_cycle_from(const Graph& graph, int vertex, vector<Colour>& colour) {
  colour[vertex] = Colour::Grey;
  for (int next : graph[vertex]) {
    if (colour[next] == Colour::Grey) return true;  // back edge
    if (colour[next] == Colour::White && has_cycle_from(graph, next, colour)) return true;
  }
  colour[vertex] = Colour::Black;
  return false;
}

bool has_directed_cycle(const Graph& graph) {
  vector<Colour> colour(graph.size(), Colour::White);
  for (size_t v = 0; v < graph.size(); ++v)
    if (colour[v] == Colour::White && has_cycle_from(graph, static_cast<int>(v), colour))
      return true;
  return false;
}

// In an undirected graph every edge looks like a back edge from the other end, so the
// parent has to be excluded. Tracking the parent rather than just "seen" is the whole
// difference from the directed case.
static bool undirected_cycle_from(const Graph& graph, int vertex, int parent,
                                 vector<bool>& seen) {
  seen[vertex] = true;
  for (int next : graph[vertex]) {
    if (next == parent) continue;
    if (seen[next]) return true;
    if (undirected_cycle_from(graph, next, vertex, seen)) return true;
  }
  return false;
}

bool has_undirected_cycle(const Graph& graph) {
  vector<bool> seen(graph.size(), false);
  for (size_t v = 0; v < graph.size(); ++v)
    if (!seen[v] && undirected_cycle_from(graph, static_cast<int>(v), -1, seen)) return true;
  return false;
}

int main() {
  Graph graph(5);
  graph[0] = {1, 2};
  graph[1] = {3};
  graph[2] = {3};
  graph[3] = {4};
  assert(dfs_order(graph, 0) == vector<int>({0, 1, 3, 4, 2}));
  // A diamond is not a cycle: two states would wrongly say it is.
  assert(!has_directed_cycle(graph));

  graph[4].push_back(0);  // close a cycle
  assert(has_directed_cycle(graph));

  // Undirected: a path is not a cycle, a triangle is.
  Graph tree(3);
  auto connect = [](Graph& g, int a, int b) { g[a].push_back(b); g[b].push_back(a); };
  connect(tree, 0, 1);
  connect(tree, 1, 2);
  assert(!has_undirected_cycle(tree));
  connect(tree, 2, 0);
  assert(has_undirected_cycle(tree));
  return 0;
}
