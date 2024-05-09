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
