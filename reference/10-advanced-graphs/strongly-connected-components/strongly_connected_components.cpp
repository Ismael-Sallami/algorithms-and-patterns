// Pattern: Strongly connected components
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check strongly_connected_components.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

using Graph = vector<vector<int>>;

// Strongly connected components: maximal sets where every vertex reaches every other.
// Contracting each one turns any directed graph into a DAG, which is what makes
// topological reasoning available on cyclic graphs.

// Tarjan: one DFS pass. Each vertex gets a discovery index and a low-link - the smallest
// index reachable from its subtree through at most one back edge. A vertex whose low-link
// equals its own index is the root of a component, and everything above it on the stack
// belongs to that component.
//
// The `on_stack` flag is what makes it correct. A neighbour already visited but no longer
// on the stack sits in a finished component and must not lower the low-link; otherwise
// separate components merge.
class Tarjan {
  const Graph& graph;
  vector<int> index_of, low_link;
  vector<bool> on_stack;
  vector<int> stack_of_vertices;
  int next_index = 0;
  vector<vector<int>> components;

  void visit(int vertex) {
    index_of[vertex] = low_link[vertex] = next_index++;
    stack_of_vertices.push_back(vertex);
    on_stack[vertex] = true;

    for (int next : graph[vertex]) {
      if (index_of[next] == -1) {
        visit(next);
        low_link[vertex] = min(low_link[vertex], low_link[next]);
      } else if (on_stack[next]) {
        low_link[vertex] = min(low_link[vertex], index_of[next]);
      }
      // else: `next` is in a finished component. Deliberately ignored.
    }

    if (low_link[vertex] != index_of[vertex]) return;
    vector<int> component;
    for (;;) {
      const int member = stack_of_vertices.back();
      stack_of_vertices.pop_back();
      on_stack[member] = false;
      component.push_back(member);
      if (member == vertex) break;
    }
    sort(component.begin(), component.end());
    components.push_back(move(component));
  }

 public:
  explicit Tarjan(const Graph& graph)
      : graph(graph), index_of(graph.size(), -1), low_link(graph.size(), 0),
        on_stack(graph.size(), false) {}

  vector<vector<int>> run() {
    for (size_t v = 0; v < graph.size(); ++v)
      if (index_of[v] == -1) visit(static_cast<int>(v));
    return components;
  }
};

// Kosaraju: two DFS passes. Finish order on the original graph, then DFS on the reversed
// graph in that order. Reversing preserves the components but flips the edges between
// them, so a traversal started at a sink of the original cannot leave its own component.
// Slower in practice - two passes and a reversed copy - and easier to argue.
class Kosaraju {
  const Graph& graph;
  Graph reversed;
  vector<bool> seen;
  vector<int> finish_order;

  void first_pass(int vertex) {
    seen[vertex] = true;
    for (int next : graph[vertex])
      if (!seen[next]) first_pass(next);
    finish_order.push_back(vertex);
  }

  void second_pass(int vertex, vector<int>& component) {
    seen[vertex] = true;
    component.push_back(vertex);
    for (int next : reversed[vertex])
      if (!seen[next]) second_pass(next, component);
  }

 public:
  explicit Kosaraju(const Graph& graph) : graph(graph), reversed(graph.size()) {
    for (size_t from = 0; from < graph.size(); ++from)
      for (int to : graph[from]) reversed[to].push_back(static_cast<int>(from));
  }

  vector<vector<int>> run() {
    seen.assign(graph.size(), false);
    for (size_t v = 0; v < graph.size(); ++v)
      if (!seen[v]) first_pass(static_cast<int>(v));

    seen.assign(graph.size(), false);
    vector<vector<int>> components;
    for (size_t i = finish_order.size(); i-- > 0;) {
      const int vertex = finish_order[i];
      if (seen[vertex]) continue;
      vector<int> component;
      second_pass(vertex, component);
      sort(component.begin(), component.end());
      components.push_back(move(component));
    }
    return components;
  }
};

static vector<vector<int>> normalise(vector<vector<int>> components) {
  sort(components.begin(), components.end());
  return components;
}

int main() {
  // Two cycles joined one way: {0,1,2} -> {3,4}, and 5 alone.
  Graph graph(6);
  graph[0] = {1};
  graph[1] = {2};
  graph[2] = {0, 3};
  graph[3] = {4};
  graph[4] = {3};

  const vector<vector<int>> expected = {{0, 1, 2}, {3, 4}, {5}};
  assert(normalise(Tarjan(graph).run()) == expected);
  // Two different algorithms must agree, which is the real test of both.
  assert(normalise(Kosaraju(graph).run()) == expected);

  // A DAG: every component is a single vertex.
  Graph dag(3);
  dag[0] = {1};
  dag[1] = {2};
  assert(Tarjan(dag).run().size() == 3);
  assert(Kosaraju(dag).run().size() == 3);

  // One big cycle: a single component.
  Graph ring(4);
  for (int v = 0; v < 4; ++v) ring[v] = {(v + 1) % 4};
  assert(Tarjan(ring).run().size() == 1);
  assert(Kosaraju(ring).run().size() == 1);

  // A self loop is a component of one, and must not be double counted.
  Graph loop(1);
  loop[0] = {0};
  assert(Tarjan(loop).run() == vector<vector<int>>({{0}}));
  return 0;
}
