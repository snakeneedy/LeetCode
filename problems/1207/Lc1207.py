from collections import defaultdict
from typing import List


class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        countMap = defaultdict(int)
        for n in arr:
            countMap[n] += 1
        counts = countMap.values()
        return len(counts) == len(set(counts))


if __name__ == '__main__':
    sol = Solution()

    arr = [1, 2, 2, 1, 1, 3]
    result = sol.uniqueOccurrences(arr)
    expected = True
    assert expected == result, f'expected {expected}, but {result}'

    arr = [1, 2]
    result = sol.uniqueOccurrences(arr)
    expected = False
    assert expected == result, f'expected {expected}, but {result}'

    arr = [-3, 0, 1, -3, 1, 1, 1, -3, 10, 0]
    result = sol.uniqueOccurrences(arr)
    expected = True
    assert expected == result, f'expected {expected}, but {result}'
