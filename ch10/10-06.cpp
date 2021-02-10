#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
  std::vector<int> v (10,1);

  for (const auto i: v) std::cout <<i <<" ";
  std::cout <<std::endl;

  std::fill_n(v.begin(), 10, 0);
  for (const auto i: v) std::cout <<i <<" ";
  std::cout <<std::endl;

  return 0;
}