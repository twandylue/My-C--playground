#include <algorithm> // std::sort
#include <cassert>   // assert
#include <iostream>  // std::cout
#include <vector>    // std::vector

using namespace std;

int get_closest(vector<int> arr, int pos1, int pos2, int target) {
  if ((target - arr[pos1]) > (arr[pos2] - target)) {
    return pos2;
  }
  return pos1;
}

int closest_binary_search(vector<int> input, int target) {
  int n = input.size();
  if (target < input[0]) {
    return 0;
  }
  if (target > input[n - 1]) {
    return n - 1;
  }

  int l = 0;
  int r = n;
  int mid = 0;
  while (l < r) {
    mid = (l + r) / 2;
    if (input[mid] == target) {
      return mid;
    }
    if (input[mid] > target) {
      if (mid > 0 && target > input[mid - 1]) {
        return get_closest(input, mid - 1, mid, target);
      }
      r = mid - 1;
    } else {
      if (mid < n - 1 && target < input[mid + 1]) {
        return get_closest(input, mid, mid + 1, target);
      }
      l = mid + 1;
    }
  }

  return mid;
}

int main() {
  vector<int> v = {1, 2, 3, 4, 5, 6, 8};
  std::sort(v.begin(), v.end());

  cout << closest_binary_search(v, 7) << endl;
  assert(closest_binary_search(v, 7) == 5);

  vector<int> v2 = {1, 2, 3, 4, 5, 6, 9};
  std::sort(v2.begin(), v2.end());

  cout << closest_binary_search(v2, 7) << endl;
  assert(closest_binary_search(v2, 7) == 5);
  cout << closest_binary_search(v2, 8) << endl;
  assert(closest_binary_search(v2, 8) == 6);

  return 0;
}
