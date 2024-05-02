from typing import List


class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        # for each row or column:
        # list of int -> list of str -> joined str -> hash
        n = len(grid)
        rowHashs = tuple(
            hash(' '.join(str(grid[i][j]) for j in range(n))) for i in range(n)
        )
        colHashs = tuple(
            hash(' '.join(str(grid[j][i]) for j in range(n))) for i in range(n)
        )
        return sum(1 if rh == ch else 0
                   for rh in rowHashs
                   for ch in colHashs)


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
