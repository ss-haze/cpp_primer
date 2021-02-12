#include <map>
#include <list>
#include <string>
#include <iostream>

using std::list;
using std::map;
using std::string;

int main()
{

  map<string, list<size_t>> m;

  m.insert({"introduction", {1, 4, 6, 7}});
  m.insert({"conclusion", {43, 26, 37}});

  for (const auto &item : m)
  {
    std::cout << item.first << ": ";
    for (const auto i : item.second)
      std::cout << i << " ";
    std::cout << std::endl;
  }
  return 0;
}