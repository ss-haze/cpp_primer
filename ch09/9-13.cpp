#include <list>
#include <vector>
#include <iostream>

int main ()
{
  std::list<int> l1 {1,2,3,4,5,6};
  std::vector<double> v1 (l1.cbegin(), l1.cend());

  std::vector<int> v2 {1,2,3,4,5,6,7,8,9,10};
  std::vector<double> v3(v2.cbegin(), v2.cend());

  std::cout <<"list<int> l1: ";
  for (const auto it: l1) std::cout << it <<" ";

  std::cout <<"\nvector<int> v1: ";
  for (const auto it: v1) std::cout << it << " ";

  std::cout <<"\nvector<int> v2: ";
  for (const auto it: v2) std::cout << it << " ";

   std::cout <<"\nvector<int> v3: ";
  for (const auto it: v3) std::cout << it << " ";

  return 0;
}