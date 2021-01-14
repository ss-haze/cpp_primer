#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char **argv)
{
  std::ifstream ifs(argv[1]);
  std::string s;
  std::vector<std::string> v;
  std::istringstream iss;

  while (getline(ifs, s))
    v.push_back(s);

  for (const auto &i : v)
  {
    iss.str(i);
    for (std::string str; iss >> str; std::cout << str << " ")
      ;
    std::cout << std::endl;
    iss.clear();
  }
  return 0;
}