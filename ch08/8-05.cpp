#include <fstream>
#include <vector>
#include <string>
#include <iostream>

void read(std::vector<std::string> &v, std::fstream &f)
{
  for (std::string s; f >> s; v.push_back(s))
    ;
}

int main()
{
  std::string ifile = "input.txt";
  std::fstream is(ifile);
  std::vector<std::string> v;

  if (is)
    read(v, is);
  else
  {
    std::cout << "There is no such file";
    return -1;
  }

  if (v.size() != 0)
  {
    for (auto i : v)
      std::cout << i << std::endl;
    if (is.eofbit)
      std::cout << "End of file reached\n";
  }
  else
    std::cout << "The file is empty";

  return 0;
}