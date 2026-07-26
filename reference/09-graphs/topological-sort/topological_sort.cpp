// Pattern: Topological sort
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check topological_sort.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

using namespace std;

using Graph = vector<vector<int>>;

// A linear order in which every edge points forwards. It exists exactly when the graph
// is acyclic, so the algorithm doubles as a cycle test - and that is usually the more
// useful half.

// Kahn's algorithm: repeatedly emit a vertex with no remaining incoming edges. If fewer
// than V vertices come out, the leftovers are inside a cycle, which is why this reports
// failure rather than producing a wrong order.
vector<int> topological_order_kahn(const Graph& graph) {
  vector<int> incoming(graph.size(), 0);
  for (const auto& edges : graph)
    for (int to : edges) ++incoming[to];

  queue<int> ready;
  for (size_t v = 0; v < graph.size(); ++v)
    if (incoming[v] == 0) ready.push(static_cast<int>(v));

  vector<int> order;
  while (!ready.empty()) {
    const int current = ready.front();
    ready.pop();
    order.push_back(current);
    for (int next : graph[current])
      if (--incoming[next] == 0) ready.push(next);
  }
  if (order.size() != graph.size()) return {};  // a cycle remains
  return order;
}

// The DFS formulation: a vertex is emitted once all its descendants are, so reversing
// the finish order gives a topological order. Shorter, but it needs the three-colour
// marking to detect a cycle.
enum class Colour { White, Grey, Black };

static bool visit(const Graph& graph, int vertex, vector<Colour>& colour, vector<int>& out) {
  colour[vertex] = Colour::Grey;
  for (int next : graph[vertex]) {
    if (colour[next] == Colour::Grey) return false;  // cycle
    if (colour[next] == Colour::White && !visit(graph, next, colour, out)) return false;
  }
  colour[vertex] = Colour::Black;
  out.push_back(vertex);
  return true;
}

vector<int> topological_order_dfs(const Graph& graph) {
  vector<Colour> colour(graph.size(), Colour::White);
  vector<int> reversed;
  for (size_t v = 0; v < graph.size(); ++v)
    if (colour[v] == Colour::White && !visit(graph, static_cast<int>(v), colour, reversed))
      return {};
  reverse(reversed.begin(), reversed.end());
  return reversed;
}

// Checks an order really is topological, independently of how it was produced.
static bool is_topological(const Graph& graph, const vector<int>& order) {
  if (order.size() != graph.size()) return false;
  vector<int> position(graph.size());
  for (size_t i = 0; i < order.size(); ++i) position[order[i]] = static_cast<int>(i);
  for (size_t from = 0; from < graph.size(); ++from)
    for (int to : graph[from])
      if (position[from] > position[to]) return false;
  return true;
}

int main() {
  // A prerequisite graph: 0 -> 1 -> 3, 0 -> 2 -> 3, 3 -> 4
  Graph graph(5);
  graph[0] = {1, 2};
  graph[1] = {3};
  graph[2] = {3};
  graph[3] = {4};

  vector<int> kahn = topological_order_kahn(graph);
  vector<int> dfs = topological_order_dfs(graph);
  assert(is_topological(graph, kahn));
  assert(is_topological(graph, dfs));
  assert(kahn.front() == 0 && kahn.back() == 4);

  // With a cycle, both must refuse rather than return something plausible.
  graph[4].push_back(0);
  assert(topological_order_kahn(graph).empty());
  assert(topological_order_dfs(graph).empty());

  // No edges: any order is valid, and every vertex must appear.
  Graph isolated(3);
  assert(topological_order_kahn(isolated).size() == 3);
  return 0;
}
