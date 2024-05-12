#include <vector>
using namespace std;

class Solution {
public:
  int max9(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6,
           int arg7, int arg8) {
    if (arg0 < arg1) arg0 = arg1;
    if (arg0 < arg2) arg0 = arg2;
    if (arg0 < arg3) arg0 = arg3;
    if (arg0 < arg4) arg0 = arg4;
    if (arg0 < arg5) arg0 = arg5;
    if (arg0 < arg6) arg0 = arg6;
    if (arg0 < arg7) arg0 = arg7;
    if (arg0 < arg8) arg0 = arg8;
    return arg0;
  }
  vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    size_t bound = grid.size() - 2;
    vector<vector<int>> result(bound);
    for (size_t rpos = 0; rpos < bound; ++rpos) {
      for (size_t cpos = 0; cpos < bound; ++cpos) {
        result[rpos].push_back(
            max9(grid[rpos][cpos], grid[rpos][cpos + 1], grid[rpos][cpos + 2],
                 grid[rpos + 1][cpos], grid[rpos + 1][cpos + 1],
                 grid[rpos + 1][cpos + 2], grid[rpos + 2][cpos],
                 grid[rpos + 2][cpos + 1], grid[rpos + 2][cpos + 2]));
      }
    }
    return result;
  }
};

int main() {
  return 0;
}
