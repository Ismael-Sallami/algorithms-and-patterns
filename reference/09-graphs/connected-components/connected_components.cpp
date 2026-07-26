// Pattern: Connected components
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check connected_components.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

using namespace std;

using Graph = vector<vector<int>>;
using Grid = vector<vector<char>>;

// Labels every vertex with its component index. One traversal per unlabelled vertex,
// and each vertex is traversed once overall, so the total is O(V + E) no matter how
// many components there are.
vector<int> label_components(const Graph& graph) {
  vector<int> component(graph.size(), -1);
  int next_label = 0;

  for (size_t start = 0; start < graph.size(); ++start) {
    if (component[start] != -1) continue;
    vector<int> stack{static_cast<int>(start)};
    component[start] = next_label;
    while (!stack.empty()) {
      const int current = stack.back();
      stack.pop_back();
      for (int next : graph[current]) {
        if (component[next] != -1) continue;
        component[next] = next_label;
        stack.push_back(next);
      }
    }
    ++next_label;
  }
  return component;
}

// Flood fill over a grid: the same algorithm where the graph is implicit and a cell's
// neighbours are computed rather than stored. Counting islands is the component count
// of that implicit graph.
//
// The grid is taken by value and mutated to mark visits, which avoids a second array.
// That is only safe because the caller keeps its own copy.
int count_regions(Grid grid, char land) {
  if (grid.empty()) return 0;
  const int rows = static_cast<int>(grid.size());
  const int cols = static_cast<int>(grid[0].size());
  int regions = 0;
  const int row_step[4] = {-1, 1, 0, 0};
  const int col_step[4] = {0, 0, -1, 1};

  for (int row = 0; row < rows; ++row)
    for (int col = 0; col < cols; ++col) {
      if (grid[row][col] != land) continue;
      ++regions;
      queue<pair<int, int>> frontier;
      frontier.push({row, col});
      grid[row][col] = '.';
      while (!frontier.empty()) {
        auto [r, c] = frontier.front();
        frontier.pop();
        for (int d = 0; d < 4; ++d) {
          const int nr = r + row_step[d], nc = c + col_step[d];
          if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
          if (grid[nr][nc] != land) continue;
          grid[nr][nc] = '.';  // mark on enqueue, or cells enter twice
          frontier.push({nr, nc});
        }
      }
    }
  return regions;
}

int main() {
  // Components {0,1,2}, {3,4}, {5}
  Graph graph(6);
  auto connect = [&](int a, int b) { graph[a].push_back(b); graph[b].push_back(a); };
  connect(0, 1); connect(1, 2); connect(3, 4);

  vector<int> labels = label_components(graph);
  assert(labels[0] == labels[1] && labels[1] == labels[2]);
  assert(labels[3] == labels[4]);
  assert(labels[0] != labels[3] && labels[3] != labels[5]);

  // Two regions: {(0,0),(0,1),(1,0)} and {(1,3),(2,3),(2,2)}.
  Grid grid = {
      {'1', '1', '0', '0'},
      {'1', '0', '0', '1'},
      {'0', '0', '1', '1'},
  };
  assert(count_regions(grid, '1') == 2);

  // Three regions, with one of them a single cell.
  Grid three = {
      {'1', '0', '1'},
      {'0', '0', '0'},
      {'1', '1', '0'},
  };
  assert(count_regions(three, '1') == 3);
  assert(count_regions({{'0', '0'}, {'0', '0'}}, '1') == 0);
  // Diagonals do not connect under a four-neighbour rule.
  assert(count_regions({{'1', '0'}, {'0', '1'}}, '1') == 2);
  return 0;
}
