from typing import List


class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        result = 0
        n = len(grid)
        for i in range(n):
            col = []
            for j in range(n):
                col.append(grid[j][i])
            for ri in range(n):
                if grid[ri] == col:
                    result += 1
        return result


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
