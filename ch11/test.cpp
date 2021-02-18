#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main()
{

  std::map<std::string, size_t> words{{"hello", 3}, {"bye", 4}};

  int x = words["hello"];

  std::cout << x + 1;

  return 0;
}