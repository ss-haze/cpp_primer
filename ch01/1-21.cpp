#include "Sales_item.h"
#include <iostream>

int main()
{
  Sales_item item1, item2;
  std::cin >> item1 >> item2;

  if (item1.isbn() == item2.isbn())
  {
    std::cout << item1 + item2 << std::endl;
  }
  else
    std::cout << "The isbn numbers are not the same" << std::endl;

  return 0;
}