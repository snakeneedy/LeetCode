#include <vector>
using namespace std;

#ifndef LIST_NODE
#define LIST_NODE

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {
  }
  ListNode(int x) : val(x), next(nullptr) {
  }
  ListNode(int x, ListNode* next) : val(x), next(next) {
  }
};

ListNode* vector2ListNode(const vector<int>& values) {
  if (values.empty())
    return nullptr;
  ListNode *head, *node;
  node = head = new ListNode(values[0]);
  for (size_t pos = 1; pos < values.size(); ++pos)
    node = node->next = new ListNode(values[pos]);
  return head;
}

vector<int> ListNode2vector(ListNode* head) {
  vector<int> values;
  for (ListNode* node = head; node != nullptr; node = node->next)
    values.push_back(node->val);
  return values;
}

#endif
