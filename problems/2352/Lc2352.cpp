#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
  int equalPairs(vector<vector<int>>& grid) {
    int result = 0;
    for (size_t i = 0, size = grid.size(); i < size; ++i) {
      vector<int> col(size);
      for (size_t j = 0; j < size; ++j)
        col[j] = grid[j][i];
      for (size_t ri = 0; ri < size; ++ri) {
        if (col == grid[ri])
          ++result;
      }
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
