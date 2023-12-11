#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int> &input) {
  for (size_t i = 0; i < input.size(); ++i) {
    for (size_t j = 0; j < input.size() - i - 1; ++j) {
      if (input[j] > input[j + 1]) {
        int tmp = input[j];
        input[j] = input[j + 1];
        input[j + 1] = tmp;
      }
    }
  }
}

int main() {
  vector<int> v = {3, 2, 1, 8, 5, 4, 7, 6};
  bubble_sort(v);
  for (size_t i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }

  return 0;
}
