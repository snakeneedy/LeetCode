#include <assert.h>
#include <stdlib.h>
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

int requests[10001];

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);

 * recentCounterFree(obj);
*/
typedef struct {
  int pos, size;
} RecentCounter;

RecentCounter* recentCounterCreate() {
  RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));
  if (obj == NULL)
    return NULL;
  obj->pos = obj->size = 0;
  return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
  int range_min = t - 3000;
  requests[obj->size++] = t;
  while (requests[obj->pos] < range_min)
    ++(obj->pos);
  return obj->size - obj->pos;
}

void recentCounterFree(RecentCounter* obj) {
  if (obj == NULL)
    return;
  free(obj);
}

void testcase01() {
  RecentCounter* obj = recentCounterCreate();
  int t_arr[] = {1, 100, 3001, 3002};
  int expected_arr[] = {1, 2, 3, 3};
  for (int pos = 0, size = ARRAY_SIZE(t_arr); pos < size; ++pos) {
    int t = t_arr[pos];
    int result = recentCounterPing(obj, t);
    int expected = expected_arr[pos];
    assert(expected == result);
  }
}

int main() {
  testcase01();
  return 0;
}
