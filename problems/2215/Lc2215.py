from typing import List


class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        set1 = set(nums1)
        set2 = set(nums2)
        return [
            list(set1.difference(set2)),
            list(set2.difference(set1)),
        ]


if __name__ == '__main__':
    sol = Solution()

    nums1 = [1, 2, 3]
    nums2 = [2, 4, 6]
    expected = [[1, 3], [4, 6]]
    result = sol.findDifference(nums1, nums2)
    assert expected == result, f'expected {expected}, but {result}'

    nums1 = [1, 2, 3, 3]
    nums2 = [1, 1, 2, 2]
    expected = [[3], []]
    result = sol.findDifference(nums1, nums2)
    assert expected == result, f'expected {expected}, but {result}'
