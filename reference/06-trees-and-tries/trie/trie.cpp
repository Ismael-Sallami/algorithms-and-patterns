// Pattern: Trie
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check trie.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <memory>
#include <string>
#include <vector>

using namespace std;

// A prefix tree. A hash set answers "is this word present" just as fast and cannot answer
// "which words start with this" without scanning everything. That prefix query is the only
// reason to pay for a trie.
class Trie {
  struct Node {
    bool terminal = false;
    unique_ptr<Node> children[26];  // lowercase ASCII only, kept deliberately small
  };
  Node root;

  const Node* descend(const string& prefix) const {
    const Node* node = &root;
    for (char c : prefix) {
      const int index = c - 'a';
      if (index < 0 || index >= 26) return nullptr;
      if (node->children[index] == nullptr) return nullptr;
      node = node->children[index].get();
    }
    return node;
  }

  static void gather(const Node* node, string& path, vector<string>& out) {
    if (node->terminal) out.push_back(path);
    for (int i = 0; i < 26; ++i) {
      if (node->children[i] == nullptr) continue;
      path.push_back(static_cast<char>('a' + i));
      gather(node->children[i].get(), path, out);
      path.pop_back();
    }
  }

 public:
  void insert(const string& word) {
    Node* node = &root;
    for (char c : word) {
      const int index = c - 'a';
      if (index < 0 || index >= 26) return;
      if (node->children[index] == nullptr) node->children[index] = make_unique<Node>();
      node = node->children[index].get();
    }
    node->terminal = true;
  }

  // A word is present only if the path exists and its last node is marked. Without the
  // mark, every prefix of a stored word would report as stored.
  bool contains(const string& word) const {
    const Node* node = descend(word);
    return node != nullptr && node->terminal;
  }

  bool has_prefix(const string& prefix) const { return descend(prefix) != nullptr; }

  vector<string> with_prefix(const string& prefix) const {
    vector<string> out;
    const Node* node = descend(prefix);
    if (node == nullptr) return out;
    string path = prefix;
    gather(node, path, out);
    return out;
  }
};

int main() {
  Trie trie;
  for (const string& word : {"car", "card", "care", "cat", "dog"}) trie.insert(word);

  assert(trie.contains("car"));
  assert(trie.contains("card"));
  assert(!trie.contains("ca"));  // a prefix is not a word
  assert(trie.has_prefix("ca"));
  assert(!trie.has_prefix("cb"));

  // Gathered in lexicographic order, because the children are walked in order.
  assert(trie.with_prefix("car") == vector<string>({"car", "card", "care"}));
  assert(trie.with_prefix("d") == vector<string>({"dog"}));
  assert(trie.with_prefix("zzz").empty());

  // The empty string: only present if inserted.
  assert(!trie.contains(""));
  trie.insert("");
  assert(trie.contains(""));
  return 0;
}
