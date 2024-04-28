#include <algorithm>
#include <cassert>
#include <set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    set<int> set1, set2;
    for (int x : nums1)
      set1.insert(x);
    for (int x : nums2)
      set2.insert(x);
    vector<int> vec1, vec2;
    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
                   inserter(vec1, vec1.begin()));
    set_difference(set2.begin(), set2.end(), set1.begin(), set1.end(),
                   inserter(vec2, vec2.begin()));
    return vector<vector<int>>({vec1, vec2});
  }
};

void testcase01() {
  Solution sol;
  vector<int> nums1({1, 2, 3});
  vector<int> nums2({2, 4, 6});
  vector<vector<int>> expected({{1, 3}, {4, 6}});
  vector<vector<int>> result = sol.findDifference(nums1, nums2);
  assert(expected == result);
}

void testcase02() {
  Solution sol;
  vector<int> nums1({1, 2, 3, 3});
  vector<int> nums2({1, 1, 2, 2});
  vector<vector<int>> expected({{3}, {}});
  vector<vector<int>> result = sol.findDifference(nums1, nums2);
  assert(expected == result);
}

int main() {
  testcase01();
  testcase02();
  return 0;
}
