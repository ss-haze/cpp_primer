#include <iostream>
#include <map>
#include <utility>

int main()
{
  std::map<int, int> m{{1, 1}, {2, 2}, {3, 3}};

  for (const auto p : m)
    std::cout << p.first << "," << p.second << " ";
  std::cout << std::endl;

  std::map<int, int>::iterator iter = m.begin();

  iter->second = 4;

  for (const auto p : m)
    std::cout << p.first << "," << p.second << " ";

  return 0;
}