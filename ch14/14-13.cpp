#include "Sales_data_expanded.h"

int main()
{
  Sales_data item1("Shakespeare_Works", 10, 5);
  Sales_data item2("Shakespeare_Works", 20, 10);

  std::cout << "item1: " << item1 << std::endl;
  std::cout << "item2: " << item2 << std::endl;

  item1 = item1 + item2;
  std::cout << "item1 + item2: " << item1 << std::endl;

  item1 += item2;
  std::cout << "item1 += item2: " << item1 << std::endl;

  item1 = item1 - item2;
  std::cout << "item1 = item1 - item2: " << item1 << std::endl;

  item1 -= item2;
  std::cout << "item1 -= item2: " << item1 << std::endl;

  return 0;
}