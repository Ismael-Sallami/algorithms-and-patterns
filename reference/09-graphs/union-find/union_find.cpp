// Pattern: Union find
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check union_find.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

// Disjoint set union. Two optimisations that only work together:
//
//   union by size keeps the trees shallow by hanging the smaller under the larger
//   path compression flattens a path to the root every time it is walked
//
// With both, the amortised cost per operation is the inverse Ackermann function, which
// is below 5 for any input that fits in memory. With neither, a chain of unions builds
// a list and each find is O(n).
class UnionFind {
  vector<int> parent;
  vector<int> tree_size;
  size_t groups;

 public:
  explicit UnionFind(size_t elements)
      : parent(elements), tree_size(elements, 1), groups(elements) {
    iota(parent.begin(), parent.end(), 0);  // everyone is their own root
  }

  int find(int x) {
    while (parent[x] != x) {
      parent[x] = parent[parent[x]];  // path halving: compresses while walking
      x = parent[x];
    }
    return x;
  }

  // Returns false when the two were already together, which is what makes this usable
  // as the cycle test inside Kruskal's algorithm.
  bool unite(int a, int b) {
    int root_a = find(a), root_b = find(b);
    if (root_a == root_b) return false;
    if (tree_size[root_a] < tree_size[root_b]) swap(root_a, root_b);
    parent[root_b] = root_a;
    tree_size[root_a] += tree_size[root_b];
    --groups;
    return true;
  }

  bool connected(int a, int b) { return find(a) == find(b); }
  size_t group_count() const { return groups; }
  int group_size(int x) { return tree_size[find(x)]; }
};

int main() {
  UnionFind sets(10);
  assert(sets.group_count() == 10);

  assert(sets.unite(0, 1));
  assert(sets.unite(1, 2));
  assert(!sets.unite(0, 2));  // already connected: the cycle signal
  assert(sets.group_count() == 8);
  assert(sets.connected(0, 2) && !sets.connected(0, 3));
  assert(sets.group_size(1) == 3);

  sets.unite(3, 4);
  sets.unite(2, 3);
  assert(sets.connected(0, 4));
  assert(sets.group_size(4) == 5);

  // A long chain, which is the case path compression exists for.
  UnionFind chain(1000);
  for (int i = 0; i + 1 < 1000; ++i) chain.unite(i, i + 1);
  assert(chain.group_count() == 1);
  assert(chain.connected(0, 999));
  assert(chain.group_size(500) == 1000);
  return 0;
}
