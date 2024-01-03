/*
 * Quick sort
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 * Stable: No
 * Sorts in place: Yes
 * Notes: In-place, not stable
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> &input) {
  for (size_t i = 0; i < input.size(); ++i) {
    cout << input[i] << " ";
  }
  cout << endl;
}

int partition(int left, int right, vector<int> &input) {
  int pivot = input[right];
  int l = left;
  for (int i = left; i < right; ++i) {
    if (input[i] < pivot) {
      std::swap(input[i], input[l]);
      l += 1;
    }
  }

  std::swap(input[l], input[right]);

  return l;
}

void quick_sort(int left, int right, vector<int> &input) {
  if (left < right) {
    int pivot = partition(left, right, input);
    quick_sort(left, pivot - 1, input);
    quick_sort(pivot + 1, right, input);
  }
}

int main() {
  vector<int> v = {3, 2, 1, 8, 5, 4, 7, 6, 10, 9, 13, 11};
  quick_sort(0, v.size() - 1, v);
  print_vector(v);

  return 0;
}
