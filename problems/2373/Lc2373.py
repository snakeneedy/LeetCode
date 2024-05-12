from typing import List


class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        bound = len(grid) - 2
        result = []
        for rpos in range(bound):
            result.append([])
            for cpos in range(bound):
                result[rpos].append(max(
                    grid[rpos][cpos],
                    grid[rpos][cpos + 1],
                    grid[rpos][cpos + 2],
                    grid[rpos + 1][cpos],
                    grid[rpos + 1][cpos + 1],
                    grid[rpos + 1][cpos + 2],
                    grid[rpos + 2][cpos],
                    grid[rpos + 2][cpos + 1],
                    grid[rpos + 2][cpos + 2],
                ))
        return result


def main():
    sol = Solution()

    grid = [[9, 9, 8, 1],
            [5, 6, 2, 6],
            [8, 2, 6, 4],
            [6, 2, 2, 2]]
    result = sol.largestLocal(grid)
    expected = [[9, 9],
                [8, 6]]
    assert expected == result, f'expected {expected}, but {result}'

    grid = [[1, 1, 1, 1, 1],
            [1, 1, 1, 1, 1],
            [1, 1, 2, 1, 1],
            [1, 1, 1, 1, 1],
            [1, 1, 1, 1, 1]]
    result = sol.largestLocal(grid)
    expected = [[2, 2, 2],
                [2, 2, 2],
                [2, 2, 2]]
    assert expected == result, f'expected {expected}, but {result}'


if __name__ == '__main__':
    main()
