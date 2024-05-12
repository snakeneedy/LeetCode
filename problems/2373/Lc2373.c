#include <stdlib.h>

int max9(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6,
         int arg7, int arg8) {
  if (arg0 < arg1) arg0 = arg1;
  if (arg0 < arg2) arg0 = arg2;
  if (arg0 < arg3) arg0 = arg3;
  if (arg0 < arg4) arg0 = arg4;
  if (arg0 < arg5) arg0 = arg5;
  if (arg0 < arg6) arg0 = arg6;
  if (arg0 < arg7) arg0 = arg7;
  if (arg0 < arg8) arg0 = arg8;
  return arg0;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize,
                   int** returnColumnSizes) {
  int bound = gridSize - 2;
  *returnSize = bound;
  *returnColumnSizes = (int*)malloc(bound * sizeof(int));
  int** result = (int**)malloc(bound * sizeof(int*));
  for (int rpos = 0; rpos < bound; ++rpos) {
    (*returnColumnSizes)[rpos] = bound;
    result[rpos] = (int*)malloc(bound * sizeof(int));
    for (int cpos = 0; cpos < bound; ++cpos) {
      result[rpos][cpos] =
          max9(grid[rpos][cpos], grid[rpos][cpos + 1], grid[rpos][cpos + 2],
               grid[rpos + 1][cpos], grid[rpos + 1][cpos + 1],
               grid[rpos + 1][cpos + 2], grid[rpos + 2][cpos],
               grid[rpos + 2][cpos + 1], grid[rpos + 2][cpos + 2]);
    }
  }
  return result;
}

int main() {
  return 0;
}
