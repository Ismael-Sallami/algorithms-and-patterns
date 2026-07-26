// Pattern: Tree traversals
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check tree_traversals.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct Node {
  int value;
  Node* left = nullptr;
  Node* right = nullptr;
  explicit Node(int v) : value(v) {}
};

// The three depth-first orders differ only in when the node is emitted relative to its
// children. Recursion makes that obvious; the iterative forms make the stack explicit,
// which is what matters when the depth can exceed the call stack.
void inorder_recursive(Node* n, vector<int>& out) {
  if (n == nullptr) return;
  inorder_recursive(n->left, out);
  out.push_back(n->value);
  inorder_recursive(n->right, out);
}

// Iterative in-order: walk left as far as possible pushing, then pop, emit, and turn
// right. The stack holds exactly the ancestors whose value is still pending.
vector<int> inorder_iterative(Node* root) {
  vector<int> out;
  stack<Node*> pending;
  Node* current = root;
  while (current != nullptr || !pending.empty()) {
    while (current != nullptr) { pending.push(current); current = current->left; }
    current = pending.top();
    pending.pop();
    out.push_back(current->value);
    current = current->right;
  }
  return out;
}

// Iterative post-order with no second stack and no visited flag: run a modified pre-order
// that visits right before left, then reverse. Reversing node-right-left gives
// left-right-node.
vector<int> postorder_iterative(Node* root) {
  vector<int> out;
  if (root == nullptr) return out;
  stack<Node*> pending;
  pending.push(root);
  while (!pending.empty()) {
    Node* n = pending.top();
    pending.pop();
    out.push_back(n->value);
    if (n->left != nullptr) pending.push(n->left);
    if (n->right != nullptr) pending.push(n->right);
  }
  reverse(out.begin(), out.end());
  return out;
}

// Breadth-first, grouped by depth. Capturing the queue size before the inner loop is what
// separates the levels; without it the levels run together.
vector<vector<int>> level_order(Node* root) {
  vector<vector<int>> levels;
  if (root == nullptr) return levels;
  queue<Node*> frontier;
  frontier.push(root);
  while (!frontier.empty()) {
    const size_t width = frontier.size();
    vector<int> level;
    for (size_t i = 0; i < width; ++i) {
      Node* n = frontier.front();
      frontier.pop();
      level.push_back(n->value);
      if (n->left != nullptr) frontier.push(n->left);
      if (n->right != nullptr) frontier.push(n->right);
    }
    levels.push_back(move(level));
  }
  return levels;
}

int main() {
  // Tree shape, children listed as (left, right):
  //   1 -> (2, 3),  2 -> (4, 5),  3, 4, 5 are leaves
  Node n1(1), n2(2), n3(3), n4(4), n5(5);
  n1.left = &n2; n1.right = &n3; n2.left = &n4; n2.right = &n5;

  vector<int> recursive;
  inorder_recursive(&n1, recursive);
  assert(recursive == vector<int>({4, 2, 5, 1, 3}));
  // The iterative form must agree with the recursive one.
  assert(inorder_iterative(&n1) == recursive);

  assert(postorder_iterative(&n1) == vector<int>({4, 5, 2, 3, 1}));
  assert(level_order(&n1) == vector<vector<int>>({{1}, {2, 3}, {4, 5}}));

  assert(inorder_iterative(nullptr).empty());
  assert(level_order(nullptr).empty());

  // A degenerate right chain: the iterative walk must not lose nodes.
  Node a(1), b(2), c(3);
  a.right = &b; b.right = &c;
  assert(inorder_iterative(&a) == vector<int>({1, 2, 3}));
  return 0;
}
