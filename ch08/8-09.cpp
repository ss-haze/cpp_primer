#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

std::istream &read(std::istream &is)
{
  for (std::string s; is >> s; std::cout << s << " ")
    ;
  is.clear();
  return is;
}

int main(int argc, char** argv)
{
  std::string line;
  std::ifstream is(argv[1]);

  for (std::istringstream sstream; getline(is, line); sstream.str(line), read(sstream));

  return 0;
}