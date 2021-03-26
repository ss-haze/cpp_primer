#include "14-23-StrVec.h"

int main()
{
  StrVec v;
  v.push_back("one");
  v.push_back("two");
  v.push_back("three");
  for (const auto &s : v)
    std::cout << s << " ";

  std::cout << std::endl;

  std::string s1("four");
  std::string s2("five");
  std::string s3("six");

  v = {s1, s2, s3};

  for (const auto &s : v)
    std::cout << s << " ";

  return 0;
}