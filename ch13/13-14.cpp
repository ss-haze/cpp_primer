#include <iostream>

class numbered
{
  friend void f(numbered s);

public:
  numbered()
      : mysn(++serial)
  {
  }

private:
  size_t mysn;
  static size_t serial;
};

size_t numbered::serial = 0;

void f(numbered s) { std::cout << s.mysn << std::endl; }

int main()
{
  numbered a, b = a, c = b;
  f(a);
  f(b);
  f(c);
}