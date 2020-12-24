#include <iostream>
#include <vector>

using std::vector;

int add(int a, int b)
{
  return a + b;
}

int subtract(int a, int b)
{
  return a - b;
}

int divide(int a, int b)
{
  return (b == 0) ? 0 : a / b;
}

int multiply(int a, int b)
{
  return a * b;
}

int main()
{
  vector<decltype(add) *> v = {add, subtract, divide, multiply};

  return 0;
}