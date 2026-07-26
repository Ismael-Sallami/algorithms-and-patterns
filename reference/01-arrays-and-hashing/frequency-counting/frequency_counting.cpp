// Pattern: Frequency counting
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check frequency_counting.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Top k most frequent values. Counting is O(n); the interesting choice is how to
// extract the top k.
//
// Bucket sort by frequency is O(n), because a frequency can never exceed n so there
// are at most n+1 buckets. Sorting the counts is O(m log m) and a size-k heap is
// O(m log k). Bucketing wins when k approaches m.
vector<int> top_k_frequent(const vector<int>& values, int k) {
  unordered_map<int, int> counts;
  for (int value : values) ++counts[value];

  vector<vector<int>> buckets(values.size() + 1);
  for (const auto& [value, count] : counts) buckets[count].push_back(value);

  vector<int> result;
  for (int frequency = static_cast<int>(buckets.size()) - 1;
       frequency >= 1 && static_cast<int>(result.size()) < k; --frequency)
    for (int value : buckets[frequency]) {
      result.push_back(value);
      if (static_cast<int>(result.size()) == k) break;
    }
  return result;
}

// Groups anagrams. The sorted letters of a word are identical for every anagram of
// it, which makes them a usable grouping key.
vector<vector<string>> group_anagrams(const vector<string>& words) {
  unordered_map<string, vector<string>> groups;
  for (const string& word : words) {
    string key = word;
    sort(key.begin(), key.end());
    groups[key].push_back(word);
  }
  vector<vector<string>> result;
  result.reserve(groups.size());
  for (auto& [key, group] : groups) result.push_back(move(group));
  return result;
}

int main() {
  vector<int> top = top_k_frequent({1, 1, 1, 2, 2, 3}, 2);
  sort(top.begin(), top.end());
  assert(top == vector<int>({1, 2}));
  assert(top_k_frequent({7}, 1) == vector<int>({7}));

  vector<vector<string>> groups = group_anagrams({"eat", "tea", "tan", "ate", "nat", "bat"});
  assert(groups.size() == 3);
  size_t largest = 0;
  for (const auto& group : groups) largest = max(largest, group.size());
  assert(largest == 3);
  return 0;
}
