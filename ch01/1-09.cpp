#include <iostream>

int main()
{
  int x = 50, sum = 0;
  while (x <= 100)
    sum += x++;
  std::cout << "The sum of the numbers from 50 to 100  inclusive is " << sum;

  return 0;
}