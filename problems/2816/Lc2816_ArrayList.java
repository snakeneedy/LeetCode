import java.util.ArrayList;

public class Lc2816_ArrayList {
  class Solution {
    public ListNode doubleIt(ListNode head) {
      ArrayList<Integer> values = new ArrayList<>();
      for (ListNode node = head; node != null; node = node.next)
        values.add(node.val << 1);
      for (int pos = values.size() - 1; pos > 0; pos--) {
        if (values.get(pos) > 9) {
          values.set(pos, values.get(pos) - 10);
          values.set(pos - 1, values.get(pos - 1) + 1);
        }
      }
      ListNode node = head.next;
      head.val = values.get(0);
      if (head.val > 9) {
        head.val -= 10;
        head = new ListNode(1, head);
      }
      for (int pos = 1; pos < values.size(); ++pos) {
        node.val = values.get(pos);
        node = node.next;
      }
      return head;
    }
  }
}
