from listnode import ListNode
from Lc2816 import Solution
# from Lc2816_list import Solution


def main():
    sol = Solution()

    head = ListNode.fromList([1, 8, 9])
    result = sol.doubleIt(head).toList()
    expected = [3, 7, 8]
    assert expected == result, f'expected {expected}, but {result}'

    head = ListNode.fromList([9, 9, 9])
    result = sol.doubleIt(head).toList()
    expected = [1, 9, 9, 8]
    assert expected == result, f'expected {expected}, but {result}'


if __name__ == '__main__':
    main()
