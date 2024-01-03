/*
 * Insertion sort
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 * Stable: No
 * Sorts in place: Yes
 * Notes: In-place, not stable
 */

#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &input) {
  for (size_t i = 0; i < input.size(); ++i) {
    int minPos = i;
    for (size_t j = i; j < input.size(); ++j) {
      if (input[j] < input[minPos]) {
        minPos = j;
      }
    }

    int tmp = input[i];
    input[i] = input[minPos];
    input[minPos] = tmp;
  }
}

int main() {
  vector<int> v = {3, 2, 1, 8, 5, 4, 7, 6};
  insertion_sort(v);
  for (size_t i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }

  return 0;
}
