#include <stdlib.h>
#include "listnode.h"

struct ListNode* ListNode_new(int val, struct ListNode* next) {
  struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
  node->val = val;
  node->next = next;
  return node;
}

struct ListNode* doubleIt(struct ListNode* head) {
  struct ListNode* node;
  int size = 0;
  for (node = head; node != NULL; node = node->next)
    ++size;
  int *values = (int*)malloc(size * sizeof(int)), pos = 0;
  for (node = head; node != NULL; node = node->next)
    values[pos++] = node->val << 1;
  for (pos = size - 1; pos > 0; --pos) {
    if (values[pos] > 9) {
      values[pos] -= 10;
      ++values[pos - 1];
    }
  }
  node = head;
  if (values[0] > 9) {
    head = ListNode_new(1, head);
    values[0] -= 10;
  }
  for (pos = 0; pos < size; ++pos) {
    node->val = values[pos];
    node = node->next;
  }
  return head;
}
