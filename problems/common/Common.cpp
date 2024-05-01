#include <iostream>
#include <vector>
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
    for (int i = 1; i < arr.size(); ++i) {
      cout << ",\n ";
      print_vector(arr[i]);
    }
  }
  cout << '}';
}

int main() {
  return 0;
}
