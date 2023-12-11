#include <iostream>
#include <vector>

using namespace std;

int binary_srot(vector<int> input, int target) {
  int index = -1;
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

  return index;
}

int main() {
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
  cout << binary_srot(v, 5) << endl;
  return 0;
}
