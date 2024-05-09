from typing import Optional
from listnode import ListNode


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
