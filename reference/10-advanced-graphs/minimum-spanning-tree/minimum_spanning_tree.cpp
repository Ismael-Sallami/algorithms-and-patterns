// Pattern: Minimum spanning tree
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check minimum_spanning_tree.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <numeric>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

// Two ways to build a minimum spanning tree. Both are greedy and both are correct for
// the same reason - the cut property: the lightest edge crossing any partition of the
// vertices belongs to some MST. They differ in which cut they look at, and that decides
// which representation suits them.
struct Edge {
  int from;
  int to;
  long long weight;
  bool operator<(const Edge& other) const { return weight < other.weight; }
};

// Kruskal: sort all edges, take each one that joins two components. The cut is implicit -
// an edge is safe exactly when its endpoints are still apart, which union-find answers in
// near-constant time. Works on an edge list, so it suits sparse graphs and needs no
// adjacency. O(E log E) for the sort, which dominates.
class UnionFind {
  vector<int> parent, size_of;

 public:
  explicit UnionFind(size_t n) : parent(n), size_of(n, 1) {
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int x) {
    while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
    return x;
  }
  bool unite(int a, int b) {
    int ra = find(a), rb = find(b);
    if (ra == rb) return false;
    if (size_of[ra] < size_of[rb]) swap(ra, rb);
    parent[rb] = ra;
    size_of[ra] += size_of[rb];
    return true;
  }
};

struct Tree {
  vector<Edge> edges;
  long long total_weight = 0;
  bool spans_everything = false;
};

Tree kruskal(size_t vertices, vector<Edge> edges) {
  sort(edges.begin(), edges.end());
  UnionFind components(vertices);
  Tree tree;
  for (const Edge& edge : edges) {
    if (!components.unite(edge.from, edge.to)) continue;  // would close a cycle
    tree.edges.push_back(edge);
    tree.total_weight += edge.weight;
    if (tree.edges.size() == vertices - 1) break;         // a tree has V-1 edges
  }
  tree.spans_everything = (vertices <= 1) || (tree.edges.size() == vertices - 1);
  return tree;
}

// Prim: grow one tree, always taking the cheapest edge leaving it. The cut is explicit -
// inside against outside - and a heap keeps the cheapest crossing edge to hand. Needs
// adjacency, and suits dense graphs where sorting every edge would be wasteful.
// O(E log V) with a binary heap.
struct WeightedEdge { int to; long long weight; };

Tree prim(const vector<vector<WeightedEdge>>& graph, int start = 0) {
  Tree tree;
  const size_t n = graph.size();
  if (n == 0) return tree;

  vector<bool> inside(n, false);
  using Entry = tuple<long long, int, int>;  // (weight, to, from)
  priority_queue<Entry, vector<Entry>, greater<Entry>> frontier;
  inside[start] = true;
  for (const WeightedEdge& edge : graph[start]) frontier.push({edge.weight, edge.to, start});

  while (!frontier.empty() && tree.edges.size() + 1 < n) {
    const auto [weight, to, from] = frontier.top();
    frontier.pop();
    if (inside[to]) continue;  // stale: already absorbed by a cheaper edge
    inside[to] = true;
    tree.edges.push_back({from, to, weight});
    tree.total_weight += weight;
    for (const WeightedEdge& edge : graph[to])
      if (!inside[edge.to]) frontier.push({edge.weight, edge.to, to});
  }
  tree.spans_everything = (n <= 1) || (tree.edges.size() == n - 1);
  return tree;
}

int main() {
  vector<Edge> edges = {{0, 1, 1}, {1, 2, 2}, {1, 3, 3}, {0, 3, 4}};
  Tree from_kruskal = kruskal(4, edges);
  assert(from_kruskal.spans_everything);
  assert(from_kruskal.edges.size() == 3);
  assert(from_kruskal.total_weight == 6);  // 1 + 2 + 3, skipping the edge of 4

  vector<vector<WeightedEdge>> graph(4);
  auto connect = [&](int a, int b, long long w) {
    graph[a].push_back({b, w});
    graph[b].push_back({a, w});
  };
  connect(0, 1, 1); connect(1, 2, 2); connect(1, 3, 3); connect(0, 3, 4);

  // Different edge order, same total: both are minimum spanning trees.
  Tree from_prim = prim(graph);
  assert(from_prim.spans_everything);
  assert(from_prim.total_weight == from_kruskal.total_weight);

  // A disconnected graph has no spanning tree, and both must say so rather than
  // returning the forest as if it were one.
  assert(!kruskal(3, {{0, 1, 1}}).spans_everything);
  vector<vector<WeightedEdge>> split(3);
  split[0].push_back({1, 1});
  split[1].push_back({0, 1});
  assert(!prim(split).spans_everything);

  assert(kruskal(1, {}).spans_everything);
  // Equal weights: any choice is minimum, so the total is what must match.
  assert(kruskal(3, {{0, 1, 5}, {1, 2, 5}, {0, 2, 5}}).total_weight == 10);
  return 0;
}
