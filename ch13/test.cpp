#include <iostream>

class HasPtr
{
public:
  HasPtr(const std::string &s = std::string(), int i = 0)
      : ps(new std::string(s)),
        i(i)
  {
  }

  HasPtr(const HasPtr &rhs)
      : ps(new std::string(*rhs.ps)),
        i(rhs.i)
  {
  }

  HasPtr &operator=(const HasPtr &rhs)
  {
    if (ps != rhs.ps)
    {
      delete ps;
      ps = new std::string(*rhs.ps);
      i = rhs.i;
    }
    return *this;
  }

  void print()
  {
    std::cout << *ps << " " << i;
  }

private:
  std::string *ps;
  int i;
};

int main()
{
  HasPtr a("Hello", 5);
  a.print();
  std::cout << std::endl;
  HasPtr b(a);
  b.print();
  std::cout << std::endl;
  HasPtr c("Bye", 7);
  c.print();
  std::cout << std::endl;
  a = c;
  a.print();
  std::cout << std::endl;
  return 0;
}
