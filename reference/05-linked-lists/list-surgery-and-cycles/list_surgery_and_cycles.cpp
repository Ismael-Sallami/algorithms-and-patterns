// Pattern: List surgery and cycles
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check list_surgery_and_cycles.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

// Pointer surgery written out rather than hidden behind a container, plus the cycle
// detection that a linked structure needs.
struct Node {
  int value;
  Node* next = nullptr;
  explicit Node(int v) : value(v) {}
};

// Iterative reversal. Three pointers, because rewiring a link destroys the way forward:
// `ahead` has to be saved before `current->next` is overwritten.
Node* reverse_list(Node* head) {
  Node* behind = nullptr;
  Node* current = head;
  while (current != nullptr) {
    Node* ahead = current->next;
    current->next = behind;
    behind = current;
    current = ahead;
  }
  return behind;
}

// Removes the k-th node from the end in one pass. Two pointers k apart: when the leader
// falls off the end, the follower is at the node before the target. A dummy head removes
// the special case of deleting the first node.
Node* remove_kth_from_end(Node* head, size_t k) {
  Node dummy(0);
  dummy.next = head;
  Node* leader = &dummy;
  for (size_t i = 0; i < k; ++i) {
    if (leader->next == nullptr) return head;  // list shorter than k
    leader = leader->next;
  }
  Node* follower = &dummy;
  while (leader->next != nullptr) {
    leader = leader->next;
    follower = follower->next;
  }
  follower->next = follower->next->next;
  return dummy.next;
}

// Floyd's tortoise and hare. Two pointers at speed 1 and 2: inside a cycle the gap closes
// by one per step, so they must meet. O(1) space against O(n) for a visited set.
bool has_cycle(Node* head) {
  Node* slow = head;
  Node* fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) return true;
  }
  return false;
}

// Where the cycle starts. After the meeting, restarting one pointer at the head and
// stepping both at speed 1 makes them meet at the entry. The reason is arithmetic: the
// distance from head to entry equals the distance from the meeting point to the entry,
// modulo the cycle length.
Node* cycle_start(Node* head) {
  Node* slow = head;
  Node* fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow != fast) continue;
    Node* walker = head;
    while (walker != slow) {
      walker = walker->next;
      slow = slow->next;
    }
    return walker;
  }
  return nullptr;
}

// The same idea on a sequence rather than a list: find the duplicate in an array of n+1
// values in 1..n, treating index -> value as a successor function. The duplicate is what
// makes two indices point at the same place, so the functional graph has a cycle and its
// entry is the answer.
int duplicate_value(const vector<int>& values) {
  int slow = values[0];
  int fast = values[values[0]];
  while (slow != fast) {
    slow = values[slow];
    fast = values[values[fast]];
  }
  slow = 0;
  while (slow != fast) {
    slow = values[slow];
    fast = values[fast];
  }
  return slow;
}

static vector<int> to_vector(Node* head) {
  vector<int> out;
  for (Node* n = head; n != nullptr; n = n->next) out.push_back(n->value);
  return out;
}

int main() {
  Node a(1), b(2), c(3), d(4);
  a.next = &b; b.next = &c; c.next = &d;
  assert(to_vector(&a) == vector<int>({1, 2, 3, 4}));

  Node* reversed = reverse_list(&a);
  assert(to_vector(reversed) == vector<int>({4, 3, 2, 1}));
  // Reversing twice restores the original.
  assert(to_vector(reverse_list(reversed)) == vector<int>({1, 2, 3, 4}));
  assert(reverse_list(nullptr) == nullptr);

  Node* shortened = remove_kth_from_end(&a, 1);  // drop the last
  assert(to_vector(shortened) == vector<int>({1, 2, 3}));
  shortened = remove_kth_from_end(shortened, 3);  // drop the first, via the dummy head
  assert(to_vector(shortened) == vector<int>({2, 3}));
  // Out of range: no change, no crash.
  assert(to_vector(remove_kth_from_end(shortened, 9)) == vector<int>({2, 3}));

  Node p(1), q(2), r(3), s(4);
  p.next = &q; q.next = &r; r.next = &s;
  assert(!has_cycle(&p));
  assert(cycle_start(&p) == nullptr);

  s.next = &q;  // close a cycle back to q
  assert(has_cycle(&p));
  assert(cycle_start(&p) == &q);

  Node self(7);
  assert(!has_cycle(&self));
  self.next = &self;  // self loop
  assert(has_cycle(&self) && cycle_start(&self) == &self);
  assert(!has_cycle(nullptr));

  assert(duplicate_value({1, 3, 4, 2, 2}) == 2);
  assert(duplicate_value({3, 1, 3, 4, 2}) == 3);
  return 0;
}
