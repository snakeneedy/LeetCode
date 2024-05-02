import java.util.Arrays;

public class Lc1657 {
  static Lc1657 leetcode = new Lc1657();

  class Solution {
    public boolean closeStrings(String word1, String word2) {
      int len1 = word1.length(),
          len2 = word2.length();
      if (len1 != len2)
        return false;
      int[] freq1 = new int[26],
          freq2 = new int[26];
      for (int pos = 0; pos < len1; pos++)
        freq1[word1.charAt(pos) - 'a']++;
      for (int pos = 0; pos < len2; pos++)
        freq2[word2.charAt(pos) - 'a']++;
      for (int pos = 0; pos < 26; ++pos) {
        if ((freq1[pos] == 0) != (freq2[pos] == 0))
          return false;
      }
      Arrays.sort(freq1);
      Arrays.sort(freq2);
      for (int pos = 0; pos < 26; ++pos) {
        if (freq1[pos] != freq2[pos])
          return false;
      }
      return true;
    }
  }

  static void testcase01() {
    Solution sol = leetcode.new Solution();
    String word1 = "abc";
    String word2 = "bca";
    boolean result = sol.closeStrings(word1, word2);
    boolean expected = true;
    assert expected == result : "expected " + String.valueOf(expected) + ", but " + String.valueOf(result);
  }

  static void testcase02() {
    Solution sol = leetcode.new Solution();
    String word1 = "a";
    String word2 = "aa";
    boolean result = sol.closeStrings(word1, word2);
    boolean expected = false;
    assert expected == result : "expected " + String.valueOf(expected) + ", but " + String.valueOf(result);
  }

  static void testcase03() {
    Solution sol = leetcode.new Solution();
    String word1 = "cabbba";
    String word2 = "abbccc";
    boolean result = sol.closeStrings(word1, word2);
    boolean expected = true;
    assert expected == result : "expected " + String.valueOf(expected) + ", but " + String.valueOf(result);
  }

  static void testcase04() {
    Solution sol = leetcode.new Solution();
    String word1 = "abbzccca";
    String word2 = "babzzczc";
    boolean result = sol.closeStrings(word1, word2);
    boolean expected = true;
    assert expected == result : "expected " + String.valueOf(expected) + ", but " + String.valueOf(result);
  }

  static void testcase05() {
    Solution sol = leetcode.new Solution();
    String word1 = "aaabbbbccddeeeeefffff";
    String word2 = "aaaaabbcccdddeeeeffff";
    boolean result = sol.closeStrings(word1, word2);
    boolean expected = false;
    assert expected == result : "expected " + String.valueOf(expected) + ", but " + String.valueOf(result);
  }

  static void testcase06() {
    Solution sol = leetcode.new Solution();
    String word1 = "uau";
    String word2 = "ssx";
    boolean result = sol.closeStrings(word1, word2);
    boolean expected = false;
    assert expected == result : "expected " + String.valueOf(expected) + ", but " + String.valueOf(result);
  }

  public static void main(String[] args) {
    testcase01();
    testcase02();
    testcase03();
    testcase04();
    testcase05();
    testcase06();
  }
}
