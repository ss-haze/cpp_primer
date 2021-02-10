#include <iostream>

int main ()
{
auto sum = [] (int a, int b) -> int {return a+b;};

int a, b;
std::cout <<" Please input two integers: ";
std::cin >>a>>b;

std::cout << "The sum of "<<a<<" and "<<b<<" is "<<sum (a,b);

  return 0;
}