public class Lc237 {
  static Lc237 leetcode = new Lc237();
  static Solution sol = leetcode.new Solution();

  /**
   * Definition for singly-linked list.
   */
  public class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
      val = x;
    }
  }

  class Solution {
    public void deleteNode(ListNode node) {
      node.val = node.next.val;
      node.next = node.next.next;

      // ListNode nextNode = node.next;
      // node.val = nextNode.val;
      // node.next = nextNode.next;
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
