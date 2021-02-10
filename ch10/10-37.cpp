#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

int main()
{
  std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> lst;

  for (auto b = v.crbegin() + 2; b != v.crend() - 2; ++b)
    lst.push_back(*b);
    
  for (const auto i : lst)
    std::cout << i << " ";

  return 0;
}