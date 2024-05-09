from typing import Optional
from listnode import ListNode


class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        pre = None
        cur = head
        if cur.val > 4:
            head = pre = ListNode(0, head)
        while cur:
            cur.val <<= 1
            if cur.val > 9:
                pre.val += 1
                cur.val -= 10
            pre = cur
            cur = cur.next
        return head
