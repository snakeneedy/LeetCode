public class Lc2816 {
  class Solution {
    public ListNode doubleIt(ListNode head) {
      ListNode pre = null, cur = head;
      if (cur.val > 4)
        pre = head = new ListNode(0, head);
      while (cur != null) {
        cur.val <<= 1;
        if (cur.val > 9) {
          pre.val++;
          cur.val -= 10;
        }
        pre = cur;
        cur = cur.next;
      }
      return head;
    }
  }
}
