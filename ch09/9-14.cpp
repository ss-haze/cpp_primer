#include <list>
#include <vector>
#include <string>
#include <iostream>

int main ()
{
  std::list<const char*> lst {"hi", "bye", "yes", "no"};

  std::vector<std::string> v1 (lst.cbegin(), lst.cend()); 

  for (const auto &it: v1) std::cout <<it <<" ";

  std::cout <<std::endl;

  std::vector<std::string> v;

  v.assign(lst.cbegin(), lst.cend());

  for (const auto &it: v) std::cout <<it <<" ";

  return 0;
}