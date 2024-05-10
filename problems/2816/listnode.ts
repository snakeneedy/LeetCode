/**
 * Definition for singly-linked list.
 */
export class ListNode {
  val: number
  next: ListNode | null
  constructor(val?: number, next?: ListNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
  }
}

export function array2ListNode(values: number[]): ListNode | null {
  if (values.length === 0) return null;
  const head = new ListNode(values[0], null);
  let node: ListNode | null = head;
  for (let idx = 1, length = values.length; idx < length; idx++)
    node = node.next = new ListNode(values[idx], null);
  return head;
};

export function ListNode2array(head: ListNode | null): number[] {
  const values: number[] = [];
  for (let node: ListNode | null = head; node != null; node = node.next)
    values.push(node.val);
  return values;
};

export default {
  ListNode,
  array2ListNode,
  ListNode2array,
};
