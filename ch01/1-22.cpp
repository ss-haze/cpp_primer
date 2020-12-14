#include "Sales_item.h"
#include <iostream>

int main()
{
 Sales_item current, total;

 if (std::cin >> total)
 {
   while (std::cin >> current && current.isbn() == total.isbn() ) total+=current;
   std::cout <<total<<std::endl;

 }
  return 0;
}