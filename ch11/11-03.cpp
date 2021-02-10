#include <iostream>
#include <fstream>
#include <string>
#include <map>

std::string plural (size_t size)
{
return (size>1 ? "times" : "time");
}

int main()
{
  std::ifstream ifs ("input.txt");
  std::map<std::string, size_t> words;

  for (std::string input; ifs >> input; ++words[input]);

  for (const auto & s: words) std::cout <<s.first<<" occured "<<s.second<<" "<<plural (s.second)<<std::endl;

  return 0;
}