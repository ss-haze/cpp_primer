#include "Chapter6.h"
#include <iostream>

int fact(int x)
{
  try
  {
    if (x < 0)
      throw std::runtime_error("Error: Input cannot be a negative number");
    if (x == 1 || x == 0)
      return 1;
    else
      return x * fact(x - 1);
  }
  catch (std::runtime_error err)
  {
    std::cout << err.what();
    return -1;
  }
}