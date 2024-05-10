import { ListNode } from './listnode';

export
function doubleIt(head: ListNode | null): ListNode | null {
  const values: number[] = [];
  let node: ListNode | null = head;
  while (node != null) {
    values.push(node.val * 2);
    node = node.next;
  }
  for (let idx = values.length - 1; idx > 0; idx--) {
    if (values[idx] > 9) {
      values[idx] -= 10;
      values[idx - 1]++;
    }
  }
  node = head;
  if (values[0] > 9) {
    head = new ListNode(1, head);
    values[0] -= 10;
  }
  let idx = 0;
  while (node != null) {
    node.val = values[idx++];
    node = node.next;
  }
  return head;
};

export default {
  doubleIt,
};
