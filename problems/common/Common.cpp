#include <algorithm>
#include <iosfwd>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// C
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdarg>
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

void print_vector(const vector<int>& arr) {
  /* expected
    {a, b, c}
  */
  cout << '{';
  if (arr.size() > 0) {
    cout << arr[0];
    for (size_t i = 1; i < arr.size(); ++i)
      cout << ", " << arr[i];
  }
  cout << '}';
}

void print_2d_vector(const vector<vector<int>>& arr) {
  /* expected
    {{a, b, c},
     {d, e, f}}
  */
  cout << '{';
  if (arr.size() > 0) {
    print_vector(arr[0]);
    for (size_t i = 1; i < arr.size(); ++i) {
      cout << ",\n ";
      print_vector(arr[i]);
    }
  }
  cout << '}';
}

int main() {
  return 0;
}
