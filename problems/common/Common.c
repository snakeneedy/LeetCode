#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

void print_array(int* arr, int size) {
  /* expected
    {a, b, c}
  */
  putchar('{');
  if (size > 0) {
    printf("%d", arr[0]);
    for (int i = 1; i < size; ++i)
      printf(", %d", arr[i]);
  }
  putchar('}');
}

void print_2d_array(int** arr, int size, int* col_sizes) {
  /* expected
    {{a, b, c},
     {d, e, f}}
  */
  putchar('{');
  if (size > 0) {
    print_array(arr[0], col_sizes[0]);
    for (int i = 1; i < size; ++i) {
      printf(",\n ");
      print_array(arr[i], col_sizes[i]);
    }
  }
  putchar('}');
}

int main() {
  return 0;
}
