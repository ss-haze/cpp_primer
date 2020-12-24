#include <iostream>

using std::cout;

void f()
{
  cout << "Called function f()\n";
}

void f(int)
{
  cout << "Called function f(int)\n";
}

void f(int, int)
{
  cout << "Called function f(int, int)\n";
}

void f(double, double = 3.14)
{
  cout << "Called function f(double, double)\n";
}

int main()
{
  //f(2.56, 42);
  f(42);
  f(42, 0);
  f(2.56, 3.14);

  return 0;
}