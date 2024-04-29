#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size,
                     int* returnSize, int** returnColumnSizes) {
  int buffer1[nums1Size], buffer2[nums2Size];
  *returnSize = 2;
  *returnColumnSizes = calloc(2, sizeof(int));

  // -1000 <= nums1[i], nums2[i] <= 1000
  bool hashtable1[2001] = {0}, hashtable2[2001] = {0};
  for (int i = 0; i < nums2Size; ++i)
    hashtable2[nums2[i] + 1000] = 1;
  for (int i = 0; i < nums1Size; ++i) {
    int hash = nums1[i] + 1000;
    if (hashtable1[hash])
      continue;
    if (!hashtable2[hash])
      buffer1[(*returnColumnSizes)[0]++] = nums1[i];
    hashtable1[hash] = 1;
  }
  for (int i = 0; i < nums2Size; ++i) {
    int hash = nums2[i] + 1000;
    if (hashtable1[hash])
      continue;
    buffer2[(*returnColumnSizes)[1]++] = nums2[i];
    hashtable1[hash] = 1;
  }

  int** result = malloc(2 * sizeof(int*));
  result[0] = malloc(((*returnColumnSizes)[0]) * sizeof(int));
  memcpy(result[0], buffer1, ((*returnColumnSizes)[0]) * sizeof(int));
  result[1] = malloc(((*returnColumnSizes)[1]) * sizeof(int));
  memcpy(result[1], buffer2, ((*returnColumnSizes)[1]) * sizeof(int));
  return result;
}

void testcase01() {
  int nums1[] = {1, 2, 3};
  int nums2[] = {2, 4, 6};
  int returnSize;
  int* returnColumnSizes = malloc(2 * sizeof(int));
  int** result =
      findDifference(nums1, ARRAY_SIZE(nums1), nums2, ARRAY_SIZE(nums2),
                     &returnSize, &returnColumnSizes);

  int enums1[] = {1, 3}, enums2[] = {4, 6};
  int* expected[] = {enums1, enums2};
  assert(returnSize == 2);
  assert(returnColumnSizes[0] == ARRAY_SIZE(enums1));
  assert(returnColumnSizes[1] == ARRAY_SIZE(enums2));
  for (int i = 0; i < returnSize; ++i) {
    for (int j = 0; j < returnColumnSizes[i]; ++j) {
      assert(expected[i][j] == result[i][j]);
    }
  }
}

void testcase02() {
  int nums1[] = {1, 2, 3, 3};
  int nums2[] = {1, 1, 2, 2};
  int returnSize;
  int* returnColumnSizes = malloc(2 * sizeof(int));
  int** result =
      findDifference(nums1, ARRAY_SIZE(nums1), nums2, ARRAY_SIZE(nums2),
                     &returnSize, &returnColumnSizes);

  int enums1[] = {3}, *enums2 = NULL;
  int* expected[] = {enums1, enums2};
  assert(returnSize == 2);
  assert(returnColumnSizes[0] == ARRAY_SIZE(enums1));
  assert(returnColumnSizes[1] == 0);
  for (int i = 0; i < returnSize; ++i) {
    for (int j = 0; j < returnColumnSizes[i]; ++j) {
      assert(expected[i][j] == result[i][j]);
    }
  }
}

void testcase03() {
  int nums1[] = {1, 1, 2, 2};
  int nums2[] = {1, 2, 3, 3};
  int returnSize;
  int* returnColumnSizes = malloc(2 * sizeof(int));
  int** result =
      findDifference(nums1, ARRAY_SIZE(nums1), nums2, ARRAY_SIZE(nums2),
                     &returnSize, &returnColumnSizes);

  int *enums1 = NULL, enums2[] = {3};
  int* expected[] = {enums1, enums2};
  assert(returnSize == 2);
  assert(returnColumnSizes[0] == 0);
  assert(returnColumnSizes[1] == ARRAY_SIZE(enums2));
  for (int i = 0; i < returnSize; ++i) {
    for (int j = 0; j < returnColumnSizes[i]; ++j) {
      assert(expected[i][j] == result[i][j]);
    }
  }
}

int main() {
  testcase01();
  testcase02();
  testcase03();
  return 0;
}
