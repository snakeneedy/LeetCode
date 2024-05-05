/**
 * Definition for singly-linked list.
 */
class ListNode {
  val: number
  next: ListNode | null
  constructor(val?: number, next?: ListNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
  }
}

/**
 Do not return anything, modify it in-place instead.
 */
function deleteNode(node: ListNode | null): void {
  // 1.
  // if (node !== null) {
  //   const nextNode = node.next;
  //   if (nextNode !== null) {
  //     node.val = nextNode.val;
  //     node.next = nextNode.next;
  //   }
  // }

  // 2.
  // if (node !== null && node.next !== null) {
  //   const nextNode = node.next;
  //   node.val = nextNode.val
  //   node.next = nextNode.next;
  // }

  // 3.
  if (node !== null && node.next !== null) {
    node.val = node.next.val
    node.next = node.next.next;
  }
};
