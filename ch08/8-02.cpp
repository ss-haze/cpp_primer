#include <iostream>
#include <string>

std::istream &read(std::istream &is)
{
  for (char s; is >> s; std::cout << s << " ")
    ;
  is.clear();
  return is;
}

int main()
{
  read(std::cin);

  return 0;
}