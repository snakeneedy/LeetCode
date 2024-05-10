import { ListNode } from './listnode';

export
function doubleIt(head: ListNode | null): ListNode | null {
  if (head != null) {
    let pre: ListNode | null = null, cur: ListNode | null = head;
    if (head.val > 4)
      pre = head = new ListNode(0, head);
    while (cur != null) {
      cur.val <<= 1;
      if (cur.val > 9 && pre != null) {
        pre.val++;
        cur.val -= 10;
      }
      pre = cur;
      cur = cur.next;
    }
  }
  return head;
};

export default {
  doubleIt,
};
