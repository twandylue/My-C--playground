#include <algorithm> // std::sort
#include <cassert>   // assert
#include <iostream>  // std::cout
#include <vector>    // std::vector

using namespace std;

int binary_search(vector<int> input, int target) {
  int left = 0;
  int right = input.size() - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (input[mid] > target) {
      right = mid - 1;
    } else if (input[mid] < target) {
      left = mid + 1;
    } else {
      return mid;
    }
  }

  return -1;
}

int main() {
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
  std::sort(v.begin(), v.end());

  cout << binary_search(v, 5) << endl;
  assert(binary_search(v, 5) == 4);

  return 0;
}
