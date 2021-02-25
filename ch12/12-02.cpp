#include "StrBlob.h"
#include <iostream>

int main()
{
  StrBlob s1;
  //std::cout << s1.back;
  //will give out_of_range error

  {
    StrBlob s2(s1);
    s2.push_back("hello");
    s2.push_back("there");
    std::cout << s2.front() << " " << s2.back() << std::endl;
  }
  std::cout << s1.front() << " " << s1.back() << std::endl;

  return 0;
}
