// Pattern: Breadth first search
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check breadth_first_search.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

using Graph = vector<vector<int>>;

// BFS on an unweighted graph gives shortest paths in edges, because it settles vertices
// in non-decreasing distance order. That is the one thing DFS cannot do.
//
// Marking on enqueue rather than on dequeue matters: without it a vertex reachable from
// several frontier vertices enters the queue several times, and the queue can grow to
// O(E).
vector<int> shortest_distances(const Graph& graph, int source) {
  vector<int> distance(graph.size(), INT_MAX);
  queue<int> frontier;
  distance[source] = 0;
  frontier.push(source);

  while (!frontier.empty()) {
    const int current = frontier.front();
    frontier.pop();
    for (int next : graph[current]) {
      if (distance[next] != INT_MAX) continue;
      distance[next] = distance[current] + 1;
      frontier.push(next);
    }
  }
  return distance;
}

// Reconstructing the path needs the predecessor of each settled vertex. One parent per
// vertex is O(V) and enough, because the BFS tree has exactly one path from the source
// to each vertex.
vector<int> shortest_path(const Graph& graph, int source, int target) {
  vector<int> parent(graph.size(), -1);
  vector<bool> seen(graph.size(), false);
  queue<int> frontier;
  seen[source] = true;
  frontier.push(source);

  while (!frontier.empty()) {
    const int current = frontier.front();
    frontier.pop();
    if (current == target) break;
    for (int next : graph[current]) {
      if (seen[next]) continue;
      seen[next] = true;
      parent[next] = current;
      frontier.push(next);
    }
  }
  if (!seen[target]) return {};

  vector<int> path;
  for (int at = target; at != -1; at = parent[at]) path.push_back(at);
  reverse(path.begin(), path.end());
  return path;
}

// Multi-source BFS: seed the queue with every source at distance zero. The result is
// the distance to the nearest source, in one traversal rather than one per source.
vector<int> distance_to_nearest(const Graph& graph, const vector<int>& sources) {
  vector<int> distance(graph.size(), INT_MAX);
  queue<int> frontier;
  for (int source : sources) {
    distance[source] = 0;
    frontier.push(source);
  }
  while (!frontier.empty()) {
    const int current = frontier.front();
    frontier.pop();
    for (int next : graph[current]) {
      if (distance[next] != INT_MAX) continue;
      distance[next] = distance[current] + 1;
      frontier.push(next);
    }
  }
  return distance;
}

int main() {
  // 0-1-3-4, 0-2-3, and 5 isolated.
  Graph graph(6);
  auto connect = [&](int a, int b) { graph[a].push_back(b); graph[b].push_back(a); };
  connect(0, 1); connect(0, 2); connect(1, 3); connect(2, 3); connect(3, 4);

  vector<int> distances = shortest_distances(graph, 0);
  assert(distances[0] == 0);
  assert(distances[1] == 1 && distances[2] == 1);
  assert(distances[3] == 2);
  assert(distances[4] == 3);
  assert(distances[5] == INT_MAX);  // unreachable

  vector<int> path = shortest_path(graph, 0, 4);
  assert(path.size() == 4);  // 0 -> {1 or 2} -> 3 -> 4
  assert(path.front() == 0 && path.back() == 4);
  assert(shortest_path(graph, 0, 5).empty());
  assert(shortest_path(graph, 2, 2) == vector<int>({2}));

  vector<int> nearest = distance_to_nearest(graph, {0, 4});
  assert(nearest[3] == 1);  // closer to 4 than to 0
  return 0;
}
