#include "listnode.hpp"

class Solution {
public:
  ListNode* doubleIt(ListNode* head) {
    vector<int> values;
    ListNode* node = head;
    size_t pos = 0;  // to replace values.size()
    while (node != nullptr) {
      values.push_back(node->val << 1);
      node = node->next;
      ++pos;
    }
    for (--pos; pos > 0; --pos) {
      if (values[pos] > 9) {
        values[pos] -= 10;
        ++values[pos - 1];
      }
    }
    node = head;
    if (values[0] > 9) {
      head = new ListNode(1, head);
      values[0] -= 10;
    }
    for (int& val : values) {
      node->val = val;
      node = node->next;
    }
    return head;
  }
};
