// Pattern: Bridges and articulation points
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check bridges_and_articulation_points.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

using Graph = vector<vector<int>>;
// A comma inside a template argument makes the preprocessor read assert()
// as taking two arguments, so the type needs a name of its own.
using Bridge = pair<int, int>;
using BridgeList = vector<Bridge>;

// The single points of failure in an undirected graph.
//
//   a bridge is an edge whose removal disconnects the graph
//   an articulation point is a vertex whose removal disconnects it
//
// Both fall out of one DFS with discovery times and low-links, where the low-link is the
// earliest discovery time reachable from a subtree without using the edge back to the
// parent.
//
//   edge (u, v) is a bridge           when low[v] > discovery[u]
//   vertex u is an articulation point when low[v] >= discovery[u] for some child v
//
// The difference between > and >= is the whole distinction: a child that can reach back
// exactly to u keeps the edge alive but still depends on u itself.
//
// The root is the special case. It has no parent to be cut from, so it is an articulation
// point only when it has more than one DFS child - meaning its subtrees are joined solely
// through it.
class Connectivity {
  const Graph& graph;
  vector<int> discovery, low;
  vector<bool> is_articulation;
  BridgeList bridges;
  int timer = 0;

  void visit(int vertex, int parent) {
    discovery[vertex] = low[vertex] = timer++;
    int children = 0;

    for (int next : graph[vertex]) {
      if (next == parent) continue;  // the tree edge back up is not a back edge
      if (discovery[next] != -1) {
        low[vertex] = min(low[vertex], discovery[next]);  // back edge
        continue;
      }
      ++children;
      visit(next, vertex);
      low[vertex] = min(low[vertex], low[next]);
      if (low[next] > discovery[vertex])
        bridges.push_back({min(vertex, next), max(vertex, next)});
      if (parent != -1 && low[next] >= discovery[vertex]) is_articulation[vertex] = true;
    }
    if (parent == -1 && children > 1) is_articulation[vertex] = true;
  }

 public:
  explicit Connectivity(const Graph& graph)
      : graph(graph), discovery(graph.size(), -1), low(graph.size(), 0),
        is_articulation(graph.size(), false) {}

  void run() {
    for (size_t v = 0; v < graph.size(); ++v)
      if (discovery[v] == -1) visit(static_cast<int>(v), -1);
    sort(bridges.begin(), bridges.end());
  }

  const BridgeList& bridge_list() const { return bridges; }

  vector<int> articulation_points() const {
    vector<int> out;
    for (size_t v = 0; v < is_articulation.size(); ++v)
      if (is_articulation[v]) out.push_back(static_cast<int>(v));
    return out;
  }
};

static void connect(Graph& g, int a, int b) {
  g[a].push_back(b);
  g[b].push_back(a);
}

int main() {
  // A path: every edge is a bridge, every interior vertex an articulation point.
  Graph path(4);
  connect(path, 0, 1); connect(path, 1, 2); connect(path, 2, 3);
  Connectivity chain(path);
  chain.run();
  assert(chain.bridge_list().size() == 3);
  assert(chain.articulation_points() == vector<int>({1, 2}));  // not the endpoints

  // A cycle: no bridges, no articulation points. Every vertex has two routes out.
  Graph ring(4);
  connect(ring, 0, 1); connect(ring, 1, 2); connect(ring, 2, 3); connect(ring, 3, 0);
  Connectivity cyclic(ring);
  cyclic.run();
  assert(cyclic.bridge_list().empty());
  assert(cyclic.articulation_points().empty());

  // Two triangles joined by one edge: that edge is the only bridge, and both of its
  // endpoints are articulation points.
  Graph dumbbell(6);
  connect(dumbbell, 0, 1); connect(dumbbell, 1, 2); connect(dumbbell, 2, 0);
  connect(dumbbell, 3, 4); connect(dumbbell, 4, 5); connect(dumbbell, 5, 3);
  connect(dumbbell, 2, 3);
  Connectivity joined(dumbbell);
  joined.run();
  assert(joined.bridge_list() == BridgeList({{2, 3}}));
  assert(joined.articulation_points() == vector<int>({2, 3}));

  // A triangle with a tail: the tail edge is a bridge, and the vertex it hangs from is an
  // articulation point even though it sits inside the cycle.
  Graph tailed(4);
  connect(tailed, 0, 1); connect(tailed, 1, 2); connect(tailed, 2, 0);
  connect(tailed, 2, 3);
  Connectivity tail(tailed);
  tail.run();
  assert(tail.bridge_list() == BridgeList({{2, 3}}));
  assert(tail.articulation_points() == vector<int>({2}));
  return 0;
}
