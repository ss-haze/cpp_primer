#include <iostream>

void reference_swap(int &a, int &b)
{
  a = a ^ b;
  b = b ^ a;
  a = a ^ b;
}

int main()
{
  for (int x, y; std::cout << "\nPlease input two numbers: ", std::cin >> x >> y, std::cout << "\nx = " << x << " and y = " << y;)
  {
    reference_swap(x, y);
    std::cout << "\nAnd after the swap function is called:\nx = " << x << " and y = " << y;
    std::cout << "\nDo you wish to repeat? (y/n) ";
    char input;
    std::cin >> input;
    if (input == 'n')
      break;
  }

  return 0;
}