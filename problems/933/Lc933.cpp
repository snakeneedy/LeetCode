#include <cassert>
#include <vector>
using namespace std;

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
class RecentCounter {
  vector<int> requests;
  size_t pos, size;

public:
  RecentCounter() {
    this->pos = this->size = 0;
  }
  int ping(int t) {
    int range_min = t - 3000;
    this->requests.push_back(t);
    ++(this->size);
    while (this->requests[this->pos] < range_min)
      ++(this->pos);
    return (this->size) - (this->pos);
  }
};

void testcase01() {
  RecentCounter* obj = new RecentCounter();
  vector<int> t_vec = {1, 100, 3001, 3002};
  vector<int> expected_vec = {1, 2, 3, 3};
  for (size_t pos = 0; pos < t_vec.size(); ++pos) {
    int t = t_vec[pos];
    int result = obj->ping(t);
    int expected = expected_vec[pos];
    assert(expected == result);
  }
}

int main() {
  testcase01();
  return 0;
}
