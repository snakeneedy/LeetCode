import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Lc1207 {
  static Lc1207 leetcode = new Lc1207();

  class Solution {
    public boolean uniqueOccurrences(int[] arr) {
      Map<Integer, Integer> numCountMap = new HashMap<>();
      for (int n : arr)
        numCountMap.put(n, numCountMap.getOrDefault(n, 0) + 1);
      Set<Integer> numCountSet = new HashSet<>(numCountMap.values());
      return numCountSet.size() == numCountMap.size();
    }
  }

  static void testcase01() {
    Solution sol = leetcode.new Solution();
    int[] arr = { 1, 2, 2, 1, 1, 3 };
    boolean result = sol.uniqueOccurrences(arr);
    boolean expected = true;
    assert expected == result : "expected" + String.valueOf(expected) + ", but " + String.valueOf(result);
  }

  static void testcase02() {
    Solution sol = leetcode.new Solution();
    int[] arr = { 1, 2 };
    boolean result = sol.uniqueOccurrences(arr);
    boolean expected = false;
    assert expected == result : "expected" + String.valueOf(expected) + ", but " + String.valueOf(result);
  }

  static void testcase03() {
    Solution sol = leetcode.new Solution();
    int[] arr = { -3, 0, 1, -3, 1, 1, 1, -3, 10, 0 };
    boolean result = sol.uniqueOccurrences(arr);
    boolean expected = true;
    assert expected == result : "expected" + String.valueOf(expected) + ", but " + String.valueOf(result);
  }

  public static void main(String[] args) {
    testcase01();
    testcase02();
    testcase03();
  }
}
