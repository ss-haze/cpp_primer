#include <iostream>

int main()
{
  //1.9
  int sum = 0;
  for (int i = 50; i <= 100; sum += i, i++);
    std::cout << sum << std::endl;

  //1.10
  for (int i = 0; i <= 10; std::cout << i++ << " ")
    ;

  //1.11 already uses a for loop

  return 0;
}