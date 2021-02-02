#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

struct PersonInfo
{
  std::string name;
  std::vector<std::string> phones;
};

bool validate(std::string s)
{
  for (const auto &c : s)
  {
    if (c < 48 || c > 57)
      return false;
  }
  return true;
}

int main(int argc, char** argv)
{
  std::string line, word;
  std::vector<PersonInfo> people;
  std::istringstream record;
  std::ofstream ofs(argv[1]);
  std::ifstream ifs ("unsorted.txt");

  while (getline(ifs, line))
  {
    PersonInfo info;
    record.str(line);
    record >> info.name;
    while (record >> word)
      info.phones.push_back(word);
    record.clear();
    people.push_back(info);
  }

  for (const auto &entry : people)
  {
    std::ostringstream formatted, badNums;
    for (const auto &num : entry.phones)
    {
      if (!validate(num))
        badNums << num<<" ";
      else
        formatted << num<<" ";
    }

    if (badNums.str().empty())
      ofs << entry.name <<" "<<formatted.str()<<std::endl;
    else
      std::cerr << entry.name << " has the following invalid number(s) " << badNums.str() << std::endl;
  }

  auto p=argv +1;
  std::cout <<*p;

  return 0;
}