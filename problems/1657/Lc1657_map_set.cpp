#include <algorithm>
#include <cassert>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool closeStrings(string word1, string word2) {
    size_t size = word1.size();
    if (size != word2.size())
      return false;
    unordered_set<char> present1, present2;
    unordered_map<char, int> freq1, freq2;
    for (size_t pos = 0; pos < size; ++pos) {
      present1.insert(word1[pos]);
      ++freq1[word1[pos]];
      present2.insert(word2[pos]);
      ++freq2[word2[pos]];
    }
    if (present1 != present2)
      return false;

    unordered_map<char, int> freq1count, freq2count;
    for (auto &pair : freq1)
      ++freq1count[pair.second];
    for (auto &pair : freq2)
      ++freq2count[pair.second];
    return freq1count == freq2count;
  }
};

void testcase01() {
  Solution sol;
  string word1 = "abc";
  string word2 = "bca";
  bool result = sol.closeStrings(word1, word2);
  bool expected = true;
  assert(expected == result);
}

void testcase02() {
  Solution sol;
  string word1 = "a";
  string word2 = "aa";
  bool result = sol.closeStrings(word1, word2);
  bool expected = false;
  assert(expected == result);
}

void testcase03() {
  Solution sol;
  string word1 = "cabbba";
  string word2 = "abbccc";
  bool result = sol.closeStrings(word1, word2);
  bool expected = true;
  assert(expected == result);
}

void testcase04() {
  Solution sol;
  string word1 = "abbzccca";
  string word2 = "babzzczc";
  bool result = sol.closeStrings(word1, word2);
  bool expected = true;
  assert(expected == result);
}

void testcase05() {
  Solution sol;
  string word1 = "aaabbbbccddeeeeefffff";
  string word2 = "aaaaabbcccdddeeeeffff";
  bool result = sol.closeStrings(word1, word2);
  bool expected = false;
  assert(expected == result);
}

void testcase06() {
  Solution sol;
  string word1 = "uau";
  string word2 = "ssx";
  bool result = sol.closeStrings(word1, word2);
  bool expected = false;
  assert(expected == result);
}

int main() {
  testcase01();
  testcase02();
  testcase03();
  testcase04();
  testcase05();
  testcase06();
  return 0;
}
