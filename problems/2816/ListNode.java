import java.util.ArrayList;

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

  static ListNode fromArray(int[] values) {
    ListNode head = null;
    if (values.length > 0) {
      ListNode node = head = new ListNode(values[0]);
      for (int pos = 1; pos < values.length; ++pos)
        node = node.next = new ListNode(values[pos]);
    }
    return head;
  }

  int[] toArray() {
    ArrayList<Integer> valueIntegers = new ArrayList<>();
    for (ListNode node = this; node != null; node = node.next)
      valueIntegers.add(node.val);
    int[] values = new int[valueIntegers.size()];
    for (int pos = 0; pos < values.length; ++pos)
      values[pos] = valueIntegers.get(pos);
    return values;
  }
}
