#include <vector>
#include <iostream>

using std::vector;

int main() {
  vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

  auto begin = v.begin();
  while (begin != v.end()) {
    ++begin;
    begin = v.insert(begin, 42);
    // v.insert(begin, 42);
    // For a vector, inserting an element invalidates any iterators after the inserted element, 
    // so any usage of this iterator will result in undefined behaviour.
    ++begin;
  }

  for (const auto i: v) std::cout <<i <<" ";

  return 0;
}