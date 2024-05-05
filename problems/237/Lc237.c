/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  struct ListNode* next;
};

void deleteNode(struct ListNode* node) {
  // 1.
  // node->val = node->next->val;
  // node->next = node->next->next;

  // 2.
  struct ListNode* next_node = node->next;
  node->val = next_node->val;
  node->next = next_node->next;
}

int main() {
  return 0;
}
