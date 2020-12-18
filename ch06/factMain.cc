#include "Chapter6.h"
#include <iostream>

int main()
{
  for (int i = 1; i < 11; ++i)
    std::cout << i << "! is " << fact(i) << std::endl;
  return 0;
}