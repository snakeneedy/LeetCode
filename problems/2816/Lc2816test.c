#include <assert.h>

#include "listnode.h"
#include "Lc2816.h"
// #include "Lc2816_array.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

struct ListNode* array2ListNode(int* values, int size) {
  if (size < 1)
    return NULL;
  struct ListNode *head, *node;
  node = head = ListNode_new(values[0], NULL);
  for (int pos = 1; pos < size; ++pos)
    node = node->next = ListNode_new(values[pos], NULL);
  return head;
}

int* ListNode2array(struct ListNode* head, int* ret_size) {
  *ret_size = 0;
  for (struct ListNode* node = head; node != NULL; node = node->next)
    ++(*ret_size);
  int* values = (int*)malloc((*ret_size) * sizeof(int));
  int pos = 0;
  for (struct ListNode* node = head; node != NULL; node = node->next)
    values[pos++] = node->val;
  return values;
}

void testcase01() {
  int values[] = {1, 8, 9};
  struct ListNode* head = array2ListNode(values, ARRAY_SIZE(values));
  struct ListNode* result_node = doubleIt(head);
  int size;
  int* result = ListNode2array(result_node, &size);
  int expected[] = {3, 7, 8};
  assert(ARRAY_SIZE(expected) == size);
  for (int pos = 0; pos < size; ++pos)
    assert(expected[pos] == result[pos]);
}

void testcase02() {
  int values[] = {9, 9, 9};
  struct ListNode* head = array2ListNode(values, ARRAY_SIZE(values));
  struct ListNode* result_node = doubleIt(head);
  int size;
  int* result = ListNode2array(result_node, &size);
  int expected[] = {1, 9, 9, 8};
  assert(ARRAY_SIZE(expected) == size);
  for (int pos = 0; pos < size; ++pos)
    assert(expected[pos] == result[pos]);
}

int main() {
  testcase01();
  testcase02();
  return 0;
}
