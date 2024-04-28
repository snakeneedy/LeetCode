public class Lc2215 {
  static Lc2215 leetcode = new Lc2215();

  class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
      Set<Integer> set1 = new HashSet<>(), set2 = new HashSet<>();
      for (int x : nums1)
        set1.add(x);
      for (int x : nums2)
        set2.add(x);

      List<Integer> list1 = new ArrayList<>(), list2 = new ArrayList<>();
      for (int x : set1) {
        if (!set2.contains(x))
          list1.add(x);
      }
      for (int x : set2) {
        if (!set1.contains(x))
          list2.add(x);
      }

      List<List<Integer>> result = new ArrayList<>();
      result.add(list1);
      result.add(list2);
      return result;
    }
  }

  static void testcase01() {
    Solution sol = leetcode.new Solution();
    int[] nums1 = { 1, 2, 3 };
    int[] nums2 = { 2, 4, 6 };
    List<List<Integer>> result = sol.findDifference(nums1, nums2);
    List<List<Integer>> expected = Arrays.asList(Arrays.asList(1, 3), Arrays.asList(4, 6));
    assert expected.equals(result) : "expected " + String.valueOf(expected) + ", but " + String.valueOf(result);
  }

  static void testcase02() {
    Solution sol = leetcode.new Solution();
    int[] nums1 = { 1, 2, 3, 3 };
    int[] nums2 = { 1, 1, 2, 2 };
    List<List<Integer>> result = sol.findDifference(nums1, nums2);
    List<List<Integer>> expected = Arrays.asList(Arrays.asList(3), Arrays.asList());
    assert expected.equals(result) : "expected " + String.valueOf(expected) + ", but " + String.valueOf(result);
  }

  public static void main(String[] args) {
    testcase01();
    testcase02();
  }
}
