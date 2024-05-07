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
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node = head
        lst = []
        while node:
            lst.append(node.val << 1)
            node = node.next
        for pos in range(len(lst) - 1, 0, -1):
            if lst[pos] > 9:
                lst[pos] -= 10
                lst[pos - 1] += 1
        node = head
        if lst[0] > 9:
            head = ListNode(1, head)
            lst[0] -= 10
        for val in lst:
            node.val = val
            node = node.next
        return head


def main():
    sol = Solution()

    head = ListNode.fromList([1, 8, 9])
    result = sol.doubleIt(head).toList()
    expected = [3, 7, 8]
    assert expected == result, f'expected {expected}, but {result}'


if __name__ == '__main__':
    main()
