from typing import Optional
from typing import List


class ListNode:
    """Definition for singly-linked list."""

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    @classmethod
    def fromList(cls, values=()):
        head = None
        node = None
        for pos, val in enumerate(values):
            if 0 < pos:
                node.next = cls(val)
                node = node.next
            else:
                head = node = cls(val)
        return head

    def toList(self) -> List[int]:
        result = []
        node = self
        while node:
            result.append(node.val)
            node = node.next
        return result


class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head.next:
            return None
        bnode, fnode = head, head.next.next  # head -> bnode -> fnode
        while fnode:
            fnode = fnode.next
            if fnode:
                bnode, fnode = bnode.next, fnode.next
        bnode.next = bnode.next.next
        return head


def main():
    sol = Solution()

    head = ListNode.fromList([1, 3, 4, 7, 1, 2, 6])
    result = sol.deleteMiddle(head).toList()
    expected = [1, 3, 4, 1, 2, 6]
    assert expected == result, f'expected {expected}, but {
        result}'

    head = ListNode.fromList([1, 3, 4, 7, 1, 2])
    result = sol.deleteMiddle(head).toList()
    expected = [1, 3, 4, 1, 2]
    assert expected == result, f'expected {expected}, but {
        result}'


if __name__ == '__main__':
    main()
