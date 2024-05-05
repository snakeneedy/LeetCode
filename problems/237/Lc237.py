# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def deleteNode(self, node):
        # 1.
        # prev = None
        # while node.next:
        #     node.val = node.next.val
        #     prev = node
        #     node = node.next
        # prev.next = None

        # 2.
        # node.val = node.next.val
        # node.next = node.next.next

        # 3.
        # node.val, node.next = node.next.val, node.next.next

        # 4.
        # nextNode = node.next
        # node.val = nextNode.val
        # node.next = nextNode.next

        # 5.
        nextNode = node.next
        node.val, node.next = nextNode.val, nextNode.next
