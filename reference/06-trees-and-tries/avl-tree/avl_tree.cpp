// Pattern: AVL tree
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check avl_tree.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

using namespace std;

// A self-balancing BST. An unbalanced tree degrades to a list on sorted input, turning
// every operation into O(n); AVL keeps the height within a constant factor of log n by
// rotating whenever a subtree's children differ in height by more than one.
//
// Four cases, two of them composites: left-left and right-right need one rotation,
// left-right and right-left need two.
struct Node {
  int key;
  int height = 1;
  Node* left = nullptr;
  Node* right = nullptr;
  explicit Node(int k) : key(k) {}
};

static int height_of(Node* n) { return n == nullptr ? 0 : n->height; }
static int balance_of(Node* n) {
  return n == nullptr ? 0 : height_of(n->left) - height_of(n->right);
}
static void refresh(Node* n) { n->height = 1 + max(height_of(n->left), height_of(n->right)); }

static Node* rotate_right(Node* pivot) {
  Node* root = pivot->left;
  pivot->left = root->right;
  root->right = pivot;
  refresh(pivot);
  refresh(root);
  return root;
}

static Node* rotate_left(Node* pivot) {
  Node* root = pivot->right;
  pivot->right = root->left;
  root->left = pivot;
  refresh(pivot);
  refresh(root);
  return root;
}

static Node* rebalance(Node* node) {
  refresh(node);
  const int balance = balance_of(node);
  if (balance > 1) {
    if (balance_of(node->left) < 0) node->left = rotate_left(node->left);  // left-right
    return rotate_right(node);
  }
  if (balance < -1) {
    if (balance_of(node->right) > 0) node->right = rotate_right(node->right);  // right-left
    return rotate_left(node);
  }
  return node;
}

static Node* insert_at(Node* node, int key) {
  if (node == nullptr) return new Node(key);
  if (key < node->key) node->left = insert_at(node->left, key);
  else if (key > node->key) node->right = insert_at(node->right, key);
  else return node;
  return rebalance(node);
}

static void collect(Node* n, vector<int>& out) {
  if (n == nullptr) return;
  collect(n->left, out);
  out.push_back(n->key);
  collect(n->right, out);
}

static void destroy(Node* n) {
  if (n == nullptr) return;
  destroy(n->left);
  destroy(n->right);
  delete n;
}

// Checks the invariant everywhere, which is the only way to know the rotations are right
// rather than merely not crashing.
static bool is_balanced(Node* n) {
  if (n == nullptr) return true;
  if (abs(balance_of(n)) > 1) return false;
  return is_balanced(n->left) && is_balanced(n->right);
}

int main() {
  Node* root = nullptr;
  // Ascending input is the worst case for a plain BST: it would build a list of height
  // 1000. AVL keeps it logarithmic.
  for (int key = 1; key <= 1000; ++key) root = insert_at(root, key);

  vector<int> keys;
  collect(root, keys);
  assert(keys.size() == 1000);
  assert(keys.front() == 1 && keys.back() == 1000);
  assert(is_balanced(root));
  assert(height_of(root) <= 15);  // log2(1000) is about 10; the AVL bound is ~1.44 log n
  destroy(root);

  // The left-right composite case specifically: 30, 10, 20.
  Node* zigzag = nullptr;
  for (int key : {30, 10, 20}) zigzag = insert_at(zigzag, key);
  assert(zigzag->key == 20);  // the middle key rises to the root
  assert(is_balanced(zigzag));
  destroy(zigzag);

  // Descending input, the mirror worst case.
  Node* descending = nullptr;
  for (int key = 100; key >= 1; --key) descending = insert_at(descending, key);
  assert(is_balanced(descending));
  assert(height_of(descending) <= 10);
  destroy(descending);
  return 0;
}
