#include <iostream>

void print(int x, int y)
{
  if (x < y)
  {
    print(y, x);
    return;
  }

  std::cout << std::endl;
  for (int i = x; i > y; i--)
    std::cout << i << " ";
}

int main()
{
  int a = 100, b = 50, c = 50, d = 0;
  print (a,b);
  std::cout <<std::endl;
  print(d, c);
}
