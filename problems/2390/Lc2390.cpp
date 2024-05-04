#include <cassert>
#include <string>
using namespace std;

class Solution {
public:
  string removeStars(string s) {
    string buffer(s);
    size_t bsize = 0;
    for (size_t rpos = 0, size = s.size(); rpos < size; ++rpos) {
      if (s[rpos] == '*') {
        if (bsize > 0)
          --bsize;
      } else {
        buffer[bsize++] = s[rpos];
      }
    }
    return buffer.substr(0, bsize);
  }
};

void testcase01() {
  Solution sol;
  string s = "leet**cod*e";
  string result = sol.removeStars(s);
  string expected = "lecoe";
  assert(expected == result);
}

void testcase02() {
  Solution sol;
  string s = "erase*****";
  string result = sol.removeStars(s);
  string expected = "";
  assert(expected == result);
}

void testcase03() {
  Solution sol;
  string s = "erase";
  string result = sol.removeStars(s);
  string expected = "erase";
  assert(expected == result);
}

int main() {
  testcase01();
  testcase02();
  testcase03();
  return 0;
}
