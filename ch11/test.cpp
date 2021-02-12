#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <map>

using std::string;
using std::vector;

int main()
{

  std::multimap<string, string> mm;

  auto iter = mm.insert(std::make_pair("Hardy, Thomas", "Tess of the D'Urbervilles"));

  mm.insert(std::multimap<string, string>::value_type("Hardy, Thomas", "Far From The Madding Crowd"));

  auto ret = mm.find("Hardy, Thomas");

  std::cout << ret->second;

  return 0;
}