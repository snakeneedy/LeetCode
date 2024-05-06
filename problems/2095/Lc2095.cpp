#include <cassert>
using namespace std;

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

class Solution {
public:
  ListNode* deleteMiddle(ListNode* head) {
    if (head->next == nullptr)
      return nullptr;
    ListNode *bnode = head, *fnode = head->next->next;
    while (fnode != nullptr) {
      fnode = fnode->next;
      if (fnode != nullptr) {
        bnode = bnode->next;
        fnode = fnode->next;
      }
    }
    bnode->next = bnode->next->next;
    return head;
  }
};

int main() {
  return 0;
}
