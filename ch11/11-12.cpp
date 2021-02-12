#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

using std::map;
using std::pair;
using std::string;
using std::vector;

int main()
{
  vector<pair<string, int>> vec;

  string s;
  int x;

  while (std::cin >> s >> x)
    vec.push_back({s, x});
 

  for (const auto &item : vec)
    std::cout << item.first << ": " << item.second << std::endl;

  return 0;
}