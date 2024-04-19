/*
 * Min Heap
 * Insertion complexity: O(log n)
 * Deletion complexity: O(log n)
 * Get minimum complexity: O(1)
 * Heapify complexity: O(n log n)
 * Space complexity: O(n)
 */

#include <algorithm> // swap
#include <assert.h>  // assert
#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
public:
  MinHeap();
  // MinHeap(const MinHeap &) = default;
  // MinHeap &operator=(const MinHeap &) = default;
  ~MinHeap();

  void heapify(vector<int> &v);
  void push(int x);
  int pop();
  int peek() const;
  void print_heap() const;

private:
  void _heapify_helper(size_t parent);
  vector<int> _heap;
};

MinHeap::MinHeap() { this->_heap = {}; }

MinHeap::~MinHeap() {}

void MinHeap::_heapify_helper(size_t parent) {
  size_t smallest = parent;
  cout << "parent: " << parent << endl;
  size_t left = 2 * smallest + 1;
  size_t right = 2 * smallest + 2;
  if (left < this->_heap.size() && this->_heap[left] < this->_heap[smallest]) {
    smallest = left;
  }
  if (right < this->_heap.size() &&
      this->_heap[right] < this->_heap[smallest]) {
    smallest = right;
  }
  if (smallest != parent) {
    swap(this->_heap[parent], this->_heap[smallest]);
    this->_heapify_helper(smallest);
  }
}

void MinHeap::heapify(vector<int> &v) {
  // NOTE: This can work as well
  // for (size_t i = 0; i < v.size(); ++i) {
  //   this->push(v[i]);
  // }

  this->_heap = v;
  for (size_t i = this->_heap.size() / 2 - 1; i-- > 0;) {
    this->_heapify_helper(i);
  }

  // NOTE: This is equvalent to the above for-loop
  // int i = this->_heap.size() / 2 - 1;
  // while (i >= 0) {
  //   this->_heapify_helper(i);
  //   --i;
  // }
}

void MinHeap::push(int x) {
  this->_heap.push_back(x);
  size_t index = this->_heap.size() - 1;
  while (index > 0 && this->_heap[index] < this->_heap[(index - 1) / 2]) {
    swap(this->_heap[index], this->_heap[(index - 1) / 2]);
    index = (index - 1) / 2;
  }
}

int MinHeap::pop() {
  if (this->_heap.empty()) {
    return -1;
  }
  int result = this->_heap[0];
  size_t size = this->_heap.size();
  this->_heap[0] = this->_heap[size - 1];
  this->_heap.pop_back();
  size_t index = 0;
  while (true) {
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;
    size_t smallest = index;
    if (left < size && this->_heap[left] < this->_heap[smallest]) {
      smallest = left;
    }
    if (right < size && this->_heap[right] < this->_heap[smallest]) {
      smallest = right;
    }
    if (smallest != index) {
      swap(this->_heap[index], this->_heap[smallest]);
      index = smallest;
    } else {
      break;
    }
  }
  return result;
}

int MinHeap::peek() const {
  if (this->_heap.empty()) {
    return -1;
  }
  return this->_heap[0];
}

void MinHeap::print_heap() const {
  for (size_t i = 0; i < this->_heap.size(); ++i) {
    cout << this->_heap[i] << " ";
  }
  cout << endl;
}

int main() {
  vector<int> v = {3, 2, 1, 8, 5, 4, 7, 6};

  // Original
  for (size_t i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }
  cout << endl;

  // Heapify
  MinHeap min_heap;
  min_heap.heapify(v);
  min_heap.push(100);
  assert(min_heap.pop() == 1);
  assert(min_heap.pop() == 2);
  min_heap.push(10);
  assert(min_heap.pop() == 3);
  min_heap.print_heap();
  assert(min_heap.pop() == 4);

  return 0;
}
