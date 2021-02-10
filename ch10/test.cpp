#include <algorithm>
#include <iostream>
#include <iterator>
#include <cctype>
#include <string>

using std::string;

int main()
{
  string s ="'heloo!'";
  std::cout <<s<<std::endl;
while (ispunct(s[s.size() - 1])) s.erase(s.size() - 1, 1);
while (ispunct(s[0])) s.erase (0,1); 
  std::cout <<s<<std::endl;
  return 0;
}
