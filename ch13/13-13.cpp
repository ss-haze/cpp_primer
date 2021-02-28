#include <iostream>
#include <vector>

struct X
{
  X() { std::cout << "X()" << std::endl; }

  X(const X &) { std::cout << "X(const X&)" << std::endl; }

  X &operator=(const X &rhs)
  {
    std::cout << "X& operator = (const X& rhs)" << std::endl;
    return *this;
  }

  ~X() { std::cout << "~X()" << std::endl; };
};

void func(const X &rx, X x)
{
  std::vector<X> v;
  v.push_back(rx);
  v.push_back(x);
}

int main()
{
  X a;
  X *p = new X;
  func(*p, *p);
  delete p;

  return 0;
}

