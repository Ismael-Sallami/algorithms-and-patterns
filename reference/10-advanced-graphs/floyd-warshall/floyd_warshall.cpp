// Pattern: Floyd-Warshall
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check floyd_warshall.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

using Matrix = vector<vector<long long>>;
constexpr long long kInfinity = (1LL << 62);

// Shortest paths between every pair of vertices.
//
// Three nested loops, and the order of them is the algorithm. The outer loop is the
// intermediate vertex k, and the invariant after iteration k is: distance[i][j] is the
// shortest path from i to j using only vertices 0..k in between. Growing the permitted
// set one vertex at a time is why this is dynamic programming and not just a triple
// loop - putting k innermost gives a wrong answer.
//
// O(V^3) time, O(V^2) space. Running Dijkstra from every vertex is O(V x E log V), which
// is better on sparse graphs; Floyd-Warshall wins on dense ones, handles negative edges,
// and is about ten lines.
Matrix all_pairs_shortest(const Matrix& weight) {
  Matrix distance = weight;
  const size_t n = distance.size();
  for (size_t k = 0; k < n; ++k)
    for (size_t i = 0; i < n; ++i) {
      if (distance[i][k] == kInfinity) continue;  // no route through k
      for (size_t j = 0; j < n; ++j) {
        if (distance[k][j] == kInfinity) continue;
        distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
      }
    }
  return distance;
}

// A negative cycle shows up as a vertex able to reach itself at negative cost.
bool has_negative_cycle(const Matrix& distance) {
  for (size_t i = 0; i < distance.size(); ++i)
    if (distance[i][i] < 0) return true;
  return false;
}

// Transitive closure: the same loop structure over booleans. Reachability is "a path
// exists" with the weights thrown away, which is Warshall's original algorithm.
vector<vector<bool>> transitive_closure(vector<vector<bool>> reachable) {
  const size_t n = reachable.size();
  for (size_t k = 0; k < n; ++k)
    for (size_t i = 0; i < n; ++i)
      if (reachable[i][k])
        for (size_t j = 0; j < n; ++j)
          if (reachable[k][j]) reachable[i][j] = true;
  return reachable;
}

static Matrix make_weights(size_t n, const vector<vector<long long>>& edges) {
  Matrix weight(n, vector<long long>(n, kInfinity));
  for (size_t i = 0; i < n; ++i) weight[i][i] = 0;
  for (const auto& edge : edges) weight[edge[0]][edge[1]] = edge[2];
  return weight;
}

int main() {
  // 0->1 (3), 1->2 (1), 0->2 (7), 2->3 (2)
  Matrix distance = all_pairs_shortest(
      make_weights(4, {{0, 1, 3}, {1, 2, 1}, {0, 2, 7}, {2, 3, 2}}));
  assert(distance[0][0] == 0);
  assert(distance[0][2] == 4);          // via 1, beating the direct edge of 7
  assert(distance[0][3] == 6);
  assert(distance[3][0] == kInfinity);  // directed: no way back
  assert(!has_negative_cycle(distance));

  // Negative edges are fine as long as no cycle is negative.
  assert(all_pairs_shortest(make_weights(3, {{0, 1, 4}, {1, 2, -3}, {0, 2, 5}}))[0][2] == 1);

  // 1->2 (-3) and 2->1 (1) form a cycle of total weight -2.
  assert(has_negative_cycle(
      all_pairs_shortest(make_weights(3, {{0, 1, 1}, {1, 2, -3}, {2, 1, 1}}))));

  vector<vector<bool>> closure = transitive_closure({
      {true, true, false, false},
      {false, true, true, false},
      {false, false, true, false},
      {false, false, false, true},
  });
  assert(closure[0][2]);   // 0 -> 1 -> 2
  assert(!closure[0][3]);  // 3 is unreachable
  assert(!closure[2][0]);
  return 0;
}
