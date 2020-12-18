#include <iostream>

void reference_swap(int &a, int &b)
{
  a = a ^ b;
  b = b ^ a;
  a = a ^ b;
}

void pointer_swap(int *p, int *q)
{
  *p = *p ^ *q;
  *q = *q ^ *p;
  *p = *p ^ *q;
}

int main()
{
  int x = 10, y = 5;
  std::cout << "x= " << x << " "
            << "y= " << y << std::endl;

  reference_swap(x, y);
  std::cout << "x= " << x << " "
            << "y= " << y << std::endl;

  pointer_swap(&x, &y);
  std::cout << "x= " << x << " "
            << "y= " << y << std::endl;

  return 0;
}