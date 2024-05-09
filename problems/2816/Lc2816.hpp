#include "listnode.hpp"

class Solution {
public:
  ListNode* doubleIt(ListNode* head) {
    ListNode *pre = nullptr, *cur = head;
    if (cur->val > 4)
      head = pre = new ListNode(0, head);
    while (cur != nullptr) {
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
};
