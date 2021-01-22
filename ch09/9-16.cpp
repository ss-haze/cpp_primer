#include <vector>
#include <list>
#include <iostream>

int main()
{
  std::vector<int> v1{1, 2, 3, 4, 5};

  std::list<int> l1{1, 2, 3, 4}, l2{1, 2, 3, 4, 5};

  std::cout << (v1 == std::vector<int>(l1.begin(), l1.end()) ? "vector and list1 are the same" : "vector and list1 are not the same") << std::endl;

  std::cout << (v1 == std::vector<int>(l2.begin(), l2.end()) ? "vector and list2 are the same" : "vector and list2 are not the same") << std::endl;

  return 0;
}