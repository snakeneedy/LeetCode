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
        length = 0
        node = head
        while node:
            length += 1
            node = node.next
        pos = length >> 1
        if pos == 0:
            return head.next
        node = head
        for _ in range(pos - 1):
            node = node.next
        node.next = node.next.next
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
