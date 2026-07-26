// Pattern: Binary search tree
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check binary_search_tree.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

// An unbalanced binary search tree, written to show where deletion is hard. Insert and
// lookup are the easy half; the three deletion cases are the reason this is worth
// writing out rather than assuming.
struct Node {
  int key;
  Node* left = nullptr;
  Node* right = nullptr;
  explicit Node(int k) : key(k) {}
};

class BST {
  Node* root = nullptr;

  static Node* insert_at(Node* node, int key) {
    if (node == nullptr) return new Node(key);
    if (key < node->key) node->left = insert_at(node->left, key);
    else if (key > node->key) node->right = insert_at(node->right, key);
    return node;  // duplicates ignored: set semantics
  }

  static Node* smallest(Node* node) {
    while (node->left != nullptr) node = node->left;
    return node;
  }

  static Node* erase_at(Node* node, int key) {
    if (node == nullptr) return nullptr;
    if (key < node->key) { node->left = erase_at(node->left, key); return node; }
    if (key > node->key) { node->right = erase_at(node->right, key); return node; }

    // Cases 1 and 2: at most one child, splice it in.
    if (node->left == nullptr) { Node* child = node->right; delete node; return child; }
    if (node->right == nullptr) { Node* child = node->left; delete node; return child; }

    // Case 3: two children. Replace the key with its in-order successor - the smallest
    // key on the right - then delete that successor, which by construction has no left
    // child and so falls into case 1.
    Node* successor = smallest(node->right);
    node->key = successor->key;
    node->right = erase_at(node->right, successor->key);
    return node;
  }

  static void collect(Node* node, vector<int>& out) {
    if (node == nullptr) return;
    collect(node->left, out);
    out.push_back(node->key);
    collect(node->right, out);
  }

  static void destroy(Node* node) {
    if (node == nullptr) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
  }

 public:
  ~BST() { destroy(root); }
  BST() = default;
  BST(const BST&) = delete;
  BST& operator=(const BST&) = delete;

  void insert(int key) { root = insert_at(root, key); }
  void erase(int key) { root = erase_at(root, key); }

  bool contains(int key) const {
    for (Node* n = root; n != nullptr;) {
      if (key == n->key) return true;
      n = key < n->key ? n->left : n->right;
    }
    return false;
  }

  // In-order traversal of a BST is the sorted order. That property is the point of the
  // invariant, and it doubles as a check that it still holds.
  vector<int> sorted_keys() const {
    vector<int> out;
    collect(root, out);
    return out;
  }
};

int main() {
  BST tree;
  for (int key : {50, 30, 70, 20, 40, 60, 80}) tree.insert(key);
  assert(tree.sorted_keys() == vector<int>({20, 30, 40, 50, 60, 70, 80}));
  assert(tree.contains(60) && !tree.contains(65));

  tree.insert(50);  // duplicate: no change
  assert(tree.sorted_keys().size() == 7);

  tree.erase(20);   // leaf
  tree.erase(70);   // two children
  tree.erase(30);   // one child
  assert(tree.sorted_keys() == vector<int>({40, 50, 60, 80}));

  tree.erase(50);   // the root, with two children
  assert(tree.sorted_keys() == vector<int>({40, 60, 80}));

  tree.erase(999);  // absent: no change, no crash
  assert(tree.sorted_keys().size() == 3);
  return 0;
}
