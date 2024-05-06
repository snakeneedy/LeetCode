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
  static fromArray(arr: number[]): ListNode | null {
    if (arr.length) {
      const head = new ListNode(arr[0]);
      let node: ListNode = head;
      for (let i = 1; i < arr.length; i += 1) {
        node.next = new ListNode(arr[i]);
        node = node.next;
      }
      return head;
    }
    return null;
  }
  toArray(): number[] {
    const result: number[] = [];
    let node: ListNode | null = this;
    while (node != null) {
      result.push(node.val);
      node = node.next;
    }
    return result;
  }
}

function deleteMiddle(head: ListNode | null): ListNode | null {
  if (head?.next == null) return null;
  let bnode: ListNode | null = head,
    fnode: ListNode | null = head.next.next;
  while (fnode != null) {
    fnode = fnode.next;
    if (fnode != null && bnode != null) {
      bnode = bnode.next;
      fnode = fnode.next;
    }
  }
  if (bnode?.next != null)
    bnode.next = bnode.next.next;
  return head;
};

function arraysEqual(arr1: any[], arr2: any[]) {
  return (arr1.length === arr2.length
    && arr1.every((val, pos) => (val === arr2[pos])));
};

function main() {
  let head: ListNode | null, node: ListNode | null, result: number[], expected: number[];

  head = ListNode.fromArray([1, 3, 4, 7, 1, 2, 6]);
  node = deleteMiddle(head);
  result = (node == null ? [] : node.toArray());
  expected = [1, 3, 4, 1, 2, 6];
  if (!arraysEqual(expected, result)) new Error(`expected ${expected}, but ${result}`);

  head = ListNode.fromArray([1, 3, 4, 7, 1, 2]);
  node = deleteMiddle(head);
  result = (node == null ? [] : node.toArray());
  expected = [1, 3, 4, 1, 2];
  if (!arraysEqual(expected, result)) new Error(`expected ${expected}, but ${result}`);
};
main();
