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
    vec.push_back( std::make_pair(s,x));
    vec.push_back(pair<string, int>(s,x));
    vec.emplace_back(s,x);  //emplace creates the space for the elements in vector and avoids unnecessary copying
 

  for (const auto &item : vec)
    std::cout << item.first << ": " << item.second << std::endl;

  return 0;
}















  