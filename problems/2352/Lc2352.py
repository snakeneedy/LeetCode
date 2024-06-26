from collections import defaultdict
from typing import List


class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        n = len(grid)
        rowFreq = defaultdict(int)
        colFreq = defaultdict(int)
        for i in range(n):
            col = tuple(grid[j][i] for j in range(n))
            rowFreq[tuple(grid[i])] += 1
            colFreq[col] += 1
        return sum(rowFreq[key] * colFreq[key] for key in rowFreq)


if __name__ == '__main__':
    sol = Solution()

    grid = [[3, 2, 1], [1, 7, 6], [2, 7, 7]]
    result = sol.equalPairs(grid)
    expected = 1
    assert expected == result, f'expected {expected}, but {result}'

    grid = [[3, 1, 2, 2], [1, 4, 4, 5], [2, 4, 2, 2], [2, 4, 2, 2]]
    result = sol.equalPairs(grid)
    expected = 3
    assert expected == result, f'expected {expected}, but {result}'
