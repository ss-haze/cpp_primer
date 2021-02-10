#include <vector>
#include <iostream>

int main () {
  std::vector<int> v {1,2,3,4,5,6,7,8,9};

  for (auto b = v.crbegin(); b!=v.crend(); ++b) std::cout <<*b <<" ";

  return 0;
}