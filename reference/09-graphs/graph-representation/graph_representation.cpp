// Pattern: Graph representation
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check graph_representation.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

// The representation decides which operations are cheap, so it is the first design
// choice in any graph problem rather than an implementation detail.
//
//                  adjacency list        adjacency matrix
//   space          O(V + E)              O(V^2)
//   has edge?      O(deg(u))             O(1)
//   neighbours     O(deg(u))             O(V)
//
// Real graphs are sparse - E closer to V than to V^2 - so the list wins on space and on
// iteration, which is what traversals do. The matrix is worth it only for dense graphs,
// or when edge existence is queried far more often than neighbours are enumerated.
class AdjacencyList {
  vector<vector<int>> neighbours_of;

 public:
  explicit AdjacencyList(size_t vertices) : neighbours_of(vertices) {}

  void add_edge(int from, int to, bool directed = false) {
    neighbours_of[from].push_back(to);
    if (!directed) neighbours_of[to].push_back(from);
  }

  const vector<int>& neighbours(int vertex) const { return neighbours_of[vertex]; }
  size_t vertex_count() const { return neighbours_of.size(); }

  size_t edge_count(bool directed = false) const {
    size_t half = 0;
    for (const auto& list : neighbours_of) half += list.size();
    return directed ? half : half / 2;
  }
};

class AdjacencyMatrix {
  vector<vector<bool>> connected;

 public:
  explicit AdjacencyMatrix(size_t vertices)
      : connected(vertices, vector<bool>(vertices, false)) {}

  void add_edge(int from, int to, bool directed = false) {
    connected[from][to] = true;
    if (!directed) connected[to][from] = true;
  }

  bool has_edge(int from, int to) const { return connected[from][to]; }

  vector<int> neighbours(int vertex) const {
    vector<int> out;
    for (size_t i = 0; i < connected.size(); ++i)
      if (connected[vertex][i]) out.push_back(static_cast<int>(i));
    return out;
  }
};

int main() {
  AdjacencyList list(4);
  list.add_edge(0, 1);
  list.add_edge(0, 2);
  list.add_edge(1, 3);
  assert(list.vertex_count() == 4);
  assert(list.edge_count() == 3);
  assert(list.neighbours(0) == vector<int>({1, 2}));
  assert(list.neighbours(3) == vector<int>({1}));

  AdjacencyMatrix matrix(4);
  matrix.add_edge(0, 1);
  matrix.add_edge(0, 2);
  assert(matrix.has_edge(0, 1) && matrix.has_edge(1, 0));  // undirected: both ways
  assert(!matrix.has_edge(1, 2));
  assert(matrix.neighbours(0) == vector<int>({1, 2}));

  AdjacencyMatrix directed(3);
  directed.add_edge(0, 1, true);
  assert(directed.has_edge(0, 1) && !directed.has_edge(1, 0));
  return 0;
}
