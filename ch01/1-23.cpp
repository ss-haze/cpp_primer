
#include <iostream>
#include "Sales_item.h"

int main()
{
  Sales_item current, item;

  if (std::cin >> current)
  {
    int cnt = 1;
    while (std::cin >> item)
    {
      if (current.isbn() == item.isbn())
        ++cnt;
      else
      {
        std::cout << current.isbn() << " sold " << cnt << " items\n";
        cnt = 1;
        current = item;
      }
    }
    std::cout << current.isbn() << " sold " << cnt << " items\n";
  }

  else
  {
    std::cerr << "No input occured\n"
              << std::endl;
    return -1;
  }

  return 0;
}