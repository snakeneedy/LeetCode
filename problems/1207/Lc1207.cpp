#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> num_count;
    for (int n : arr)
      ++num_count[n];
    unordered_set<int> count_set;
    for (pair<const int, int> &pair : num_count) {
      if (count_set.contains(pair.second))
        return false;
      count_set.insert(pair.second);
    }
    return true;
  }
};

void testcase01() {
  Solution sol;
  vector<int> arr({1, 2, 2, 1, 1, 3});
  bool result = sol.uniqueOccurrences(arr);
  bool expected = true;
  assert(expected == result);
}

void testcase02() {
  Solution sol;
  vector<int> arr({1, 2});
  bool result = sol.uniqueOccurrences(arr);
  bool expected = false;
  assert(expected == result);
}

void testcase03() {
  Solution sol;
  vector<int> arr({-3, 0, 1, -3, 1, 1, 1, -3, 10, 0});
  bool result = sol.uniqueOccurrences(arr);
  bool expected = true;
  assert(expected == result);
}

int main() {
  testcase01();
  testcase02();
  testcase03();
  return 0;
}
