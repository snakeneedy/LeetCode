public class Lc2352 {
  static Lc2352 leetcode = new Lc2352();
  static Solution sol = leetcode.new Solution();

  class Solution {
    public int equalPairs(int[][] grid) {
      int result = 0, len = grid.length;
      for (int[] row : grid) {
        for (int j = 0; j < len; j++) {
          boolean isEqual = true;
          for (int k = 0; k < len; k++) {
            if (row[k] != grid[k][j]) {
              isEqual = false;
              break;
            }
          }
          if (isEqual)
            result++;
        }
      }
      return result;
    }
  }

  static void testcase01() {
    int[][] grid = { { 3, 2, 1 }, { 1, 7, 6 }, { 2, 7, 7 } };
    int result = sol.equalPairs(grid);
    int expected = 1;
    assert expected == result : "expected" + String.valueOf(expected) + ", but " + String.valueOf(result);
  }

  static void testcase02() {
    int[][] grid = { { 3, 1, 2, 2 }, { 1, 4, 4, 5 }, { 2, 4, 2, 2 }, { 2, 4, 2, 2 } };
    int result = sol.equalPairs(grid);
    int expected = 3;
    assert expected == result : "expected" + String.valueOf(expected) + ", but " + String.valueOf(result);
  }

  public static void main(String[] args) {
    testcase01();
    testcase02();
  }
}
