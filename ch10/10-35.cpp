#include <vector>
#include <iostream>

int main () {
  std::vector<int> v {1,2,3,4,5,6,7,8,9};

  for (auto e=--v.end(); e+1 != v.begin(); --e) std::cout <<*e <<" ";

  return 0;
}