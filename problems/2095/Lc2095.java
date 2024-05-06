public class Lc2095 {
  static Lc2095 leetcode = new Lc2095();
  static Solution sol = leetcode.new Solution();

  /**
   * Definition for singly-linked list.
   */
  public class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
      this.val = val;
    }

    ListNode(int val, ListNode next) {
      this.val = val;
      this.next = next;
    }
  }

  class Solution {
    public ListNode deleteMiddle(ListNode head) {
      if (head.next == null)
        return null;
      ListNode bnode = head, fnode = head.next.next;
      while (fnode != null) {
        fnode = fnode.next;
        if (fnode != null) {
          bnode = bnode.next;
          fnode = fnode.next;
        }
      }
      bnode.next = bnode.next.next;
      return head;
    }
  }

  public static void main(String[] args) {
  }
}
