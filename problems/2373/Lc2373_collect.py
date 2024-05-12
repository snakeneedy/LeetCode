from typing import List


class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        # collect max of every 3 values in a column of grid into `colgrid`
        colgrid = [
            [max(grid[0][colpos], grid[1][colpos], grid[2][colpos])
             for colpos in range(n)]
        ]
        for rowpos in range(1, n-2):
            colmax = []
            for colpos in range(n):
                newVal = grid[rowpos+2][colpos]
                if colgrid[rowpos-1][colpos] < newVal:
                    colmax.append(newVal)
                elif colgrid[rowpos-1][colpos] == grid[rowpos-1][colpos]:
                    colmax.append(
                        max(grid[rowpos][colpos], grid[rowpos+1][colpos], grid[rowpos+2][colpos]))
                else:
                    colmax.append(colgrid[rowpos-1][colpos])
            colgrid.append(colmax)
        # compare every 3 values in a row of colgrid into `result`
        result = []
        for row in colgrid:
            resultrow = [max(row[0:3])]
            for col in range(1, n-2):
                newVal = row[col+2]
                if resultrow[-1] < newVal:
                    resultrow.append(newVal)
                elif resultrow[-1] == row[col-1]:
                    resultrow.append(max(row[col], row[col+1], row[col+2]))
                else:
                    resultrow.append(resultrow[-1])
            result.append(resultrow)
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
