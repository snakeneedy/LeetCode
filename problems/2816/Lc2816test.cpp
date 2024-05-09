#include <assert.h>
#include "listnode.hpp"
#include "Lc2816.hpp"
// #include "Lc2816_vector.hpp"

void testcase01() {
  Solution sol;
  ListNode* head = vector2ListNode({1, 8, 9});
  vector<int> result = ListNode2vector(sol.doubleIt(head));
  vector<int> expected = {3, 7, 8};
  assert(expected == result);
}

void testcase02() {
  Solution sol;
  ListNode* head = vector2ListNode({9, 9, 9});
  vector<int> result = ListNode2vector(sol.doubleIt(head));
  vector<int> expected = {1, 9, 9, 8};
  assert(expected == result);
}

int main() {
  testcase01();
  testcase02();
  return 0;
}
