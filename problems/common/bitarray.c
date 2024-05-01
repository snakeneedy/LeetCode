// bitarray.c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

typedef struct bitarray bitarray;
struct bitarray {
  unsigned long size;
  unsigned char *data;
};
bitarray *bitarray_new(unsigned long size) {
  bitarray *barr = (bitarray *)malloc(sizeof(bitarray));
  if (barr == NULL)
    return NULL;
  barr->size = size;
  barr->data = (unsigned char *)calloc((size + 7) >> 3, sizeof(unsigned char));
  if (barr == NULL) {
    free(barr);
    return NULL;
  }
  return barr;
}
void bitarray_delete(bitarray *barr) {
  if (barr == NULL)
    return;
  if (barr->data != NULL)
    free(barr->data);
  free(barr);
}
void bitarray_set(bitarray *barr, unsigned long pos) {
  if (barr->size <= pos)
    return;
  unsigned char *byte = barr->data + (pos >> 3);
  *byte |= 1 << (pos & 7);
}
void bitarray_unset(bitarray *barr, unsigned long pos) {
  if (barr->size <= pos)
    return;
  unsigned char *byte = barr->data + (pos >> 3);
  *byte &= ~(1 << (pos & 7));
}
unsigned char bitarray_get(bitarray *barr, unsigned long pos) {
  if (barr->size <= pos)
    return 2;
  unsigned char *byte = barr->data + (pos >> 3);
  return ((*byte) >> (pos & 7)) & 1;
}

int main() {
  bitarray *barr = bitarray_new(32);
  for (unsigned long i = 0; i < 16; ++i) {
    bitarray_set(barr, i);
    printf("%u\t%u\n", *(barr->data + 1), *(barr->data));
    bitarray_unset(barr, i);
  }
  int positions[] = {0, 1, 2, 3, 5, 7, 11, 17};
  for (int i = 0; i < ARRAY_SIZE(positions); ++i)
    bitarray_set(barr, positions[i]);
  for (int i = 31; i >= 0; --i)
    printf("%u", bitarray_get(barr, i));
  putchar('\n');
  return 0;
}
