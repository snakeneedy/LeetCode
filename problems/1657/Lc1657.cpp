#include <algorithm>
#include <array>
#include <cassert>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size())
      return false;
    array<int, 26> freq1 = {0}, freq2 = {0};
    for (char &ch : word1)
      ++freq1[ch - 'a'];
    for (char &ch : word2)
      ++freq2[ch - 'a'];
    for (size_t pos = 0; pos < 26; ++pos) {
      if ((freq1[pos] == 0) != (freq2[pos] == 0))
        return false;
    }
    sort(freq1.begin(), freq1.end());
    sort(freq2.begin(), freq2.end());
    return freq1 == freq2;
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
