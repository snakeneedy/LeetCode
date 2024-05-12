public class Lc2373 {
  static Lc2373 leetcode = new Lc2373();
  static Solution sol = leetcode.new Solution();

  class Solution {
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

    public int[][] largestLocal(int[][] grid) {
      int bound = grid.length - 2;
      int[][] result = new int[bound][bound];
      for (int rpos = 0; rpos < bound; ++rpos) {
        for (int cpos = 0; cpos < bound; ++cpos) {
          result[rpos][cpos] = max9(grid[rpos][cpos], grid[rpos][cpos + 1], grid[rpos][cpos + 2],
              grid[rpos + 1][cpos], grid[rpos + 1][cpos + 1],
              grid[rpos + 1][cpos + 2], grid[rpos + 2][cpos],
              grid[rpos + 2][cpos + 1], grid[rpos + 2][cpos + 2]);
        }
      }
      return result;
    }
  }

  static void testcase01() {
    // assert expected.equals(result) : "expected" + String.valueOf(expected) + ",
    // but " + String.valueOf(result);
  }

  public static void main(String[] args) {
    testcase01();
  }
}
