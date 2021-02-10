#include <algorithm>
#include <iostream>
#include <list>

int main()
{
  std::list<int> lst = {1, 2, 3, 4, 0, 5, 0, 6, 7, 0, 8, 9};
  auto iter = std::find(lst.crbegin(), lst.crend(), 0);
  std::cout << "Last 0 found at position " << (std::distance(iter, lst.crend()) - 1);

  return 0;
}