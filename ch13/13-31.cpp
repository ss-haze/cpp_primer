#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class HasPtr
{
public:
  friend void swap(HasPtr &lhs, HasPtr &rhs);

  HasPtr(const std::string &s = std::string(), int x = 0)
      : ps(new std::string(s)),
        i(x)
  {
  }

  HasPtr(const HasPtr &rhs)
      : ps(new std::string(*rhs.ps)),
        i(rhs.i)
  {
  }

  ~HasPtr()
  {
    delete ps;
  }

  HasPtr &operator=(const HasPtr &rhs)
  {
    auto temp = new std::string(*rhs.ps);
    delete ps;
    ps = temp;
    i = rhs.i;
    return *this;
  }

  inline bool operator<(const HasPtr &rhs) const
  {
    return *ps < *rhs.ps;
  }

  inline void print() const
  {
    std::cout << *ps << " " << i << std::endl;
  }

private:
  std::string *ps;
  int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
  std::cout << "Swap function invoked\n";
}

int main()
{
  HasPtr a("hello", 5);
  HasPtr b("bye", 10);
  HasPtr c("yes", 3);
  std::vector<HasPtr> vec{c, a, b};

  for (const auto &item : vec)
    item.print();

  std::sort(vec.begin(), vec.end());

  for (const auto &item : vec)
    item.print();

  return 0;
}