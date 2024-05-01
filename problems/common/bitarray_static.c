// bitarray_static.c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

#define BITARRAY_SIZE 1024
unsigned char bitarray_data[(BITARRAY_SIZE + 7) >> 3];
void bitarray_static_init() {
  unsigned long bitarray_data_size = (BITARRAY_SIZE + 7) >> 3;
  memset(bitarray_data, 0, BITARRAY_SIZE);
}
void bitarray_static_set(unsigned long pos) {
  if (BITARRAY_SIZE <= pos)
    return;
  unsigned char *byte = bitarray_data + (pos >> 3);
  *byte |= 1 << (pos & 7);
}
void bitarray_static_unset(unsigned long pos) {
  if (BITARRAY_SIZE <= pos)
    return;
  unsigned char *byte = bitarray_data + (pos >> 3);
  *byte &= ~(1 << (pos & 7));
}
unsigned char bitarray_static_get(unsigned long pos) {
  if (BITARRAY_SIZE <= pos)
    return 2;
  unsigned char *byte = bitarray_data + (pos >> 3);
  return ((*byte) >> (pos & 7)) & 1;
}

int main() {
  bitarray_static_init();
  for (unsigned long i = 0; i < 16; ++i) {
    bitarray_static_set(i);
    printf("%u\t%u\n", *(bitarray_data + 1), *(bitarray_data));
    bitarray_static_unset(i);
  }
  int positions[] = {0, 1, 2, 3, 5, 7, 11, 17};
  for (int i = 0; i < ARRAY_SIZE(positions); ++i)
    bitarray_static_set(positions[i]);
  for (int i = 31; i >= 0; --i)
    printf("%u", bitarray_static_get(i));
  putchar('\n');
  return 0;
}
