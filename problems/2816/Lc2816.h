#include <stdlib.h>
#include "listnode.h"

struct ListNode* ListNode_new(int val, struct ListNode* next) {
  struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
  node->val = val;
  node->next = next;
  return node;
}

struct ListNode* doubleIt(struct ListNode* head) {
  struct ListNode *pre = NULL, *cur = head;
  if (cur->val > 4)
    head = pre = ListNode_new(0, head);
  while (cur != NULL) {
    cur->val <<= 1;
    if (cur->val > 9) {
      ++(pre->val);
      cur->val -= 10;
    }
    pre = cur;
    cur = cur->next;
  }
  return head;
}
