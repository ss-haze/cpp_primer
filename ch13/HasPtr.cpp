#include "HasPtr.h"

HasPtr::~HasPtr()
{
  delete ps;
}

HasPtr::HasPtr(const std::string &s, int x)
    : ps(new std::string(s)),
      i(x)
{
  std::cout << "Default Constructor invoked\n";
}

HasPtr::HasPtr(const HasPtr &rhs)
    : ps(new std::string(*rhs.ps)),
      i(rhs.i)
{
  std::cout << "Copy constructor invoked\n";
}

HasPtr::HasPtr(HasPtr &&rhs) noexcept
    : i(rhs.i),
      ps(rhs.ps)
{
  rhs.ps = nullptr;
  std::cout << "Move constructor invoked\n";
}

HasPtr &HasPtr::operator=(HasPtr rhs)
{
  swap(*this, rhs);
  return *this;
}

HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
  auto temp = new std::string(*rhs.ps);
  delete ps;
  ps = temp;
  i = rhs.i;
  return *this;
}

HasPtr &HasPtr::operator=(HasPtr&& rhs)
{
  if (this!=&rhs)
  {
    delete ps;
    ps=rhs.ps;
    i=rhs.i;
    rhs.ps=nullptr;
  }
  return *this;
}

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
  std::cout << "Swap function invoked\n";
}