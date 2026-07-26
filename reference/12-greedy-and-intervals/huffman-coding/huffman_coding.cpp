// Pattern: Huffman coding
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check huffman_coding.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Huffman coding: the optimal prefix-free code for a known symbol distribution.
//
// The greedy step is to merge the two least frequent symbols repeatedly. It is safe by an
// exchange argument: in any optimal tree the two rarest symbols can be moved to the deepest
// pair of sibling leaves without increasing the total, so merging them first loses nothing.
//
// Prefix-free is what makes it decodable without separators - no code is a prefix of
// another, which falls out of every symbol being a leaf. The result is optimal among
// per-symbol codes; beating it requires modelling correlations between symbols, which is
// what arithmetic coding and the LZ family do.
struct Node {
  long long weight;
  char symbol = 0;
  Node* left = nullptr;
  Node* right = nullptr;
  bool is_leaf() const { return left == nullptr && right == nullptr; }
};

struct Heavier {
  bool operator()(const Node* a, const Node* b) const {
    // Ties broken on the symbol so the tree is deterministic, which is what makes the
    // encoder and decoder agree without transmitting the tree.
    if (a->weight != b->weight) return a->weight > b->weight;
    return a->symbol > b->symbol;
  }
};

class Huffman {
  vector<unique_ptr<Node>> arena;  // owns every node, so the tree needs no destructor
  Node* root = nullptr;
  unordered_map<char, string> codes;

  Node* make(long long weight, char symbol, Node* left = nullptr, Node* right = nullptr) {
    arena.push_back(make_unique<Node>());
    Node* node = arena.back().get();
    node->weight = weight;
    node->symbol = symbol;
    node->left = left;
    node->right = right;
    return node;
  }

  void assign(Node* node, const string& prefix) {
    if (node == nullptr) return;
    if (node->is_leaf()) {
      // A single distinct symbol still needs one bit, or its code would be empty.
      codes[node->symbol] = prefix.empty() ? "0" : prefix;
      return;
    }
    assign(node->left, prefix + "0");
    assign(node->right, prefix + "1");
  }

 public:
  explicit Huffman(const string& text) {
    unordered_map<char, long long> counts;
    for (char c : text) ++counts[c];
    if (counts.empty()) return;

    priority_queue<Node*, vector<Node*>, Heavier> pending;
    for (const auto& [symbol, count] : counts) pending.push(make(count, symbol));

    while (pending.size() > 1) {
      Node* a = pending.top(); pending.pop();
      Node* b = pending.top(); pending.pop();
      pending.push(make(a->weight + b->weight, min(a->symbol, b->symbol), a, b));
    }
    root = pending.top();
    assign(root, "");
  }

  string encode(const string& text) const {
    string bits;
    for (char c : text) bits += codes.at(c);
    return bits;
  }

  string decode(const string& bits) const {
    string out;
    if (root == nullptr) return out;
    if (root->is_leaf()) {  // one distinct symbol: every bit is one occurrence
      out.assign(bits.size(), root->symbol);
      return out;
    }
    const Node* node = root;
    for (char bit : bits) {
      node = (bit == '0') ? node->left : node->right;
      if (!node->is_leaf()) continue;
      out.push_back(node->symbol);
      node = root;
    }
    return out;
  }

  size_t code_length(char symbol) const { return codes.at(symbol).size(); }
};

int main() {
  const string text = "aaaabbbccd";  // a:4 b:3 c:2 d:1
  Huffman coder(text);

  // Round trip is the requirement; the exact bit patterns are an implementation detail.
  const string bits = coder.encode(text);
  assert(coder.decode(bits) == text);

  // Frequency order must be reflected in code length: rarer symbols get longer codes.
  assert(coder.code_length('a') <= coder.code_length('b'));
  assert(coder.code_length('b') <= coder.code_length('d'));
  assert(coder.code_length('a') < coder.code_length('d'));

  // The compression itself: 10 characters at 8 bits each is 80, and this beats it.
  assert(bits.size() < text.size() * 8);
  assert(bits.size() == 19);  // 4*1 + 3*2 + 2*3 + 1*3

  // A single distinct symbol is the edge case that produces an empty code without the
  // guard, and then decoding never terminates.
  Huffman flat("aaaa");
  assert(flat.code_length('a') == 1);
  assert(flat.decode(flat.encode("aaaa")) == "aaaa");

  // Uniform frequencies: every code is the same length, so nothing is gained.
  Huffman uniform("abcd");
  const string uniform_bits = uniform.encode("abcd");
  assert(uniform_bits.size() == 8);  // 4 symbols, 2 bits each
  assert(uniform.decode(uniform_bits) == "abcd");
  return 0;
}
