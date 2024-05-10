import java.util.Arrays;

public class Lc2816test {
  static Lc2816 leetcode = new Lc2816();
  static Lc2816.Solution sol = leetcode.new Solution();
  // static Lc2816_ArrayList leetcode = new Lc2816_ArrayList();
  // static Lc2816_ArrayList.Solution sol = leetcode.new Solution();

  static public boolean equalArrays(int[] lValues, int[] rValues) {
    if (lValues == null || rValues == null || lValues.length != rValues.length)
      return false;
    for (int pos = 0; pos < lValues.length; ++pos) {
      if (lValues[pos] != rValues[pos])
        return false;
    }
    return true;
  }

  static void testcase01() {
    int[] values = { 1, 8, 9 };
    ListNode head = ListNode.fromArray(values);
    int[] result = sol.doubleIt(head).toArray();
    int[] expected = { 3, 7, 8 };
    Arrays.asList(result);
    assert equalArrays(expected, result)
        : "expected " + Arrays.toString(expected) + ", but " + Arrays.toString(result);
  }

  static void testcase02() {
    int[] values = { 9, 9, 9 };
    ListNode head = ListNode.fromArray(values);
    int[] result = sol.doubleIt(head).toArray();
    int[] expected = { 1, 9, 9, 8 };
    assert equalArrays(expected, result)
        : "expected " + Arrays.toString(expected) + ", but " + Arrays.toString(result);
  }

  public static void main(String[] args) {
    testcase01();
    testcase02();
  }
}
