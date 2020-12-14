#include <iostream>

int main()
{
  std::cout << "Enter two numbers:" << std::endl;
  int x = 0, y = 0;
  std::cin >> x >> y;
  std::cout << "The product of " << x << " and " << y << " is " << x * y << std::endl;

  return 0;
}