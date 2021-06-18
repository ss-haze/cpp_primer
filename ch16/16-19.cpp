#include <iostream>
#include <string>
#include <list>
#include <vector>

template <typename T>
std::ostream &print(const T &ctr, std::ostream &os)
{
  for (typename T::size_type i = 0; i != ctr.size(); ++i)
  {
    os << ctr[i] << " ";
  }
  return os;
}

int main()
{
  std::string s{"one two three four five"};
  std::vector<int> vi{6, 7, 8, 9};
  print(s, std::cout) << '\n';
  print(vi, std::cout) << '\n';
  return 0;
}