#include "StrBlobUpdated.h"
#include "StrBlobPtr.h"

#include <iostream>

int main()
{
  std::initializer_list<std::string> il{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  StrBlob s1(il);

  auto iter = s1.begin();
  for (decltype(s1.size()) b = 0; b != s1.size(); ++b)
  {
    std::cout << iter.deref() << " ";
    iter.incr();
  }

  return 0;
}