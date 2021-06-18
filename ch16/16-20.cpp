#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace::std;

template <typename T>
std::ostream &print(const T &ctr, std::ostream &os)
{
  for (auto it = ctr.begin(); it != ctr.end(); ++it)
  {
    os << *it << " ";
  }
  return os;
}

int main()
{
  std::list<std::string> lst{"one", "two", "three", "four", "five"};
  std::vector<int> vi{6, 7, 8, 9};
  print(lst, std::cout) << '\n';
  print(vi, std::cout) << '\n';

  return 0;
}