#include <iostream>

int main()
{
  int i = 0, &r = i;
  const int ci = i, &cr = ci;

  auto a = r;
  auto b = ci;
  auto c = cr;
  auto d = &i;
  auto e = &ci;

  const auto f = ci;
  auto &g = ci;

  a = 42; //ok, i = 42;
  b = 42; //ok, b is an int
  c = 42; //ok, c is an int
  //d = 42; illegal. d is a ptr to int, and must be assigned an int address.
  //e = 42; illegal. e is a pointer to a const int, and must be assigned an int address.
  //g = 42; illegal. g is a const int reference to a const int, and cannot be assigned to.

  return 0;
}