#include <cstddef>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {
  }
};

class Solution {
public:
  void deleteNode(ListNode* node) {
    // 1.
    // node->val = node->next->val;
    // node->next = node->next->next;

    // 2.
    ListNode* next_node = node->next;
    node->val = next_node->val;
    node->next = next_node->next;
  }
};

int main() {
  return 0;
}
