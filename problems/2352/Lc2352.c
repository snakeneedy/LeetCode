#include <assert.h>
#include <stdbool.h>

int equalPairs(int** grid, int gridSize, int* gridColSize) {
  int result = 0;
  for (int i = 0; i < gridSize; ++i) {
    int *row = grid[i];
    for (int j = 0; j < gridSize; ++j) {
      bool is_equal = true;
      for (int k = 0; k < gridSize; ++k) {
        if (row[k] != grid[k][j]) {
          is_equal = false;
          break;
        }
      }
      if (is_equal)
        ++result;
    }
  }
  return result;
}

void testcase01() {
  int gridSize = 3;
  int gridColSize[gridSize];
  for (int i = 0; i < gridSize; ++i)
    gridColSize[i] = gridSize;
  int grid0[] = {3, 2, 1};
  int grid1[] = {1, 7, 6};
  int grid2[] = {2, 7, 7};
  int* grid[] = {grid0, grid1, grid2};
  int result = equalPairs(grid, gridSize, gridColSize);
  int expected = 1;
  assert(expected == result);
}

void testcase02() {
  int gridSize = 4;
  int gridColSize[gridSize];
  for (int i = 0; i < gridSize; ++i)
    gridColSize[i] = gridSize;
  int grid0[] = {3, 1, 2, 2};
  int grid1[] = {1, 4, 4, 5};
  int grid2[] = {2, 4, 2, 2};
  int grid3[] = {2, 4, 2, 2};
  int* grid[] = {grid0, grid1, grid2, grid3};
  int result = equalPairs(grid, gridSize, gridColSize);
  int expected = 3;
  assert(expected == result);
}

int main() {
  testcase01();
  testcase02();
  return 0;
}
