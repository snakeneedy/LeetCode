#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

bool uniqueOccurrences(int* arr, int arrSize) {
  // -1000 <= arr[i] <= 1000
  int hash_count[2001] = {0};
  int hash_set[arrSize], hash_set_size = 0;
  for (int i = 0; i < arrSize; ++i) {
    int hash = arr[i] + 1000;
    if (hash_count[hash] == 0)
      hash_set[hash_set_size++] = hash;
    ++hash_count[hash];
  }
  bool has_hash_count[1001] = {0};
  for (int i = 0; i < hash_set_size; ++i) {
    int hash = hash_set[i];
    int count = hash_count[hash];
    if (has_hash_count[count])
      return false;
    has_hash_count[count] = 1;
  }
  return true;
}

void testcase01() {
  int arr[] = {1, 2, 2, 1, 1, 3};
  bool result = uniqueOccurrences(arr, ARRAY_SIZE(arr));
  bool expected = true;
  assert(expected == result);
}

void testcase02() {
  int arr[] = {1, 2};
  bool result = uniqueOccurrences(arr, ARRAY_SIZE(arr));
  bool expected = false;
  assert(expected == result);
}

void testcase03() {
  int arr[] = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
  bool result = uniqueOccurrences(arr, ARRAY_SIZE(arr));
  bool expected = true;
  assert(expected == result);
}

int main() {
  testcase01();
  testcase02();
  testcase03();
  return 0;
}
