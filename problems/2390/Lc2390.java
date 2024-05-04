public class Lc2390 {
  static Lc2390 leetcode = new Lc2390();
  static Solution sol = leetcode.new Solution();

  class Solution {
    public String removeStars(String s) {
      char[] buf = s.toCharArray();
      int bufSize = 0;
      for (int pos = 0, len = buf.length; pos < len; pos++) {
        if (buf[pos] == '*') {
          if (bufSize > 0)
            --bufSize;
        } else {
          buf[bufSize++] = buf[pos];
        }
      }
      return new String(buf, 0, bufSize);
    }
  }

  static void testcase01() {
    String s = "leet**cod*e";
    String result = sol.removeStars(s);
    String expected = "lecoe";
    assert expected.equals(result) : "expected" + String.valueOf(expected) + ", but " + String.valueOf(result);
  }

  static void testcase02() {
    String s = "erase*****";
    String result = sol.removeStars(s);
    String expected = "";
    assert expected.equals(result) : "expected" + String.valueOf(expected) + ", but " + String.valueOf(result);
  }

  static void testcase03() {
    String s = "erase";
    String result = sol.removeStars(s);
    String expected = "erase";
    assert expected.equals(result) : "expected" + String.valueOf(expected) + ", but " + String.valueOf(result);
  }

  public static void main(String[] args) {
    testcase01();
    testcase02();
    testcase03();
  }
}
