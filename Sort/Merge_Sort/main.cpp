/*
 * Merge Sort
 * Time complexity: O(nlogn)
 * Space complexity: O(n)
 * Stable: Yes
 * Sorts in place: No
 * Notes: not In-place, stable
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> &nums) {
  for (size_t i = 0; i < nums.size(); ++i) {
    cout << nums[i] << " ";
  }
  cout << endl;
}

vector<int> merge(vector<int> &left, vector<int> &right) {
  vector<int> result = vector<int>(left.size() + right.size());
  size_t index = 0;
  size_t l = 0;
  size_t r = 0;
  while (l < left.size() && r < right.size() && index < result.size()) {
    if (left[l] < right[r]) {
      result.at(index) = left[l];
      l += 1;
    } else {
      result.at(index) = right[r];
      r += 1;
    }
    index += 1;
  }
  while (l < left.size() && index < result.size()) {
    result.at(index) = left[l];
    l += 1;
    index += 1;
  }
  while (r < right.size() && index < result.size()) {
    result.at(index) = right[r];
    r += 1;
    index += 1;
  }
  return result;
}

vector<int> merge_sort(vector<int> &nums) {
  if (nums.size() <= 1) {
    return nums;
  }
  if (nums.size() == 2) {
    if (nums[0] < nums[1]) {
      return vector<int>{nums[0], nums[1]};
    }
    return vector<int>{nums[1], nums[0]};
  }
  int l = 0;
  int r = nums.size() - 1;
  int mid = (l + r) / 2;
  vector<int> left_part = vector<int>(nums.begin(), nums.begin() + mid);
  vector<int> right_part = vector<int>(nums.begin() + mid, nums.end());
  vector<int> left = merge_sort(left_part);
  vector<int> right = merge_sort(right_part);

  return merge(left, right);
}

int main() {
  vector<int> vec = {3, 2, 1, 5, 4, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  vector<int> result = merge_sort(vec);
  print_vector(result);

  return 0;
}
