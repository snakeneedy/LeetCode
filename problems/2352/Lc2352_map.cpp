#include <cassert>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int equalPairs(vector<vector<int>>& grid) {
    unordered_map<string, int> row_freq;
    for (vector<int>& row : grid) {
      stringstream ss;
      for (int& n : row)
        ss << n << ',';
      ++row_freq[ss.str()];
    }
    int result = 0;
    size_t size = grid.size();
    for (size_t i = 0; i < size; ++i) {
      stringstream ss;
      for (size_t j = 0; j < size; ++j)
        ss << grid[j][i] << ',';
      string key = ss.str();
      if (row_freq.find(key) != row_freq.end())
        result += row_freq[key];
    }
    return result;
  }
};

void testcase01() {
  Solution sol;
  vector<vector<int>> grid = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
  int result = sol.equalPairs(grid);
  int expected = 1;
  assert(expected == result);
}

void testcase02() {
  Solution sol;
  vector<vector<int>> grid = {
      {3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
  int result = sol.equalPairs(grid);
  int expected = 3;
  assert(expected == result);
}

int main() {
  testcase01();
  testcase02();
  return 0;
}
