#include <string>
#include <iostream>

class HasPtr
{
public:
  HasPtr(const std::string &s = std::string())
      : ps(new std::string(s)),
        use(new size_t(1)),
        i(0)
  {
  }

  HasPtr(const HasPtr &rhs)
      : ps(rhs.ps),
        use(rhs.use),
        i(rhs.i)
  {
    ++*rhs.use;
  }

  ~HasPtr()
  {
    if (--*use == 0)
    {
      delete use;
      delete ps;
    }
  }

  HasPtr &operator=(const HasPtr &rhs)
  {
    ++*rhs.use;
    if (--*use == 0)
    {
      delete use;
      delete ps;
    }
    ps = rhs.ps;
    use = rhs.use;
    i = rhs.i;
    return *this;
  }

private:
  std::string *ps;
  std::size_t *use;
  int i;
};

int main()
{
  return 0;
}