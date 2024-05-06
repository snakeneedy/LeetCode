#include <stddef.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* deleteMiddle(struct ListNode* head) {
  if (head->next == NULL)
    return NULL;
  struct ListNode *bnode = head, *fnode = head->next->next;
  while (fnode != NULL) {
    fnode = fnode->next;
    if (fnode != NULL) {
      bnode = bnode->next;
      fnode = fnode->next;
    }
  }
  bnode->next = bnode->next->next;
  return head;
}

int main() {
  return 0;
}
