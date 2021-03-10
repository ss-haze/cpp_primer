#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class HasPtr
{
public:
  friend void swap(HasPtr &lhs, HasPtr &rhs);

  HasPtr(const std::string &s = std::string(), int x = 0);
  HasPtr(const HasPtr &rhs);
  HasPtr(HasPtr &&rhs) noexcept;
  ~HasPtr();

  HasPtr &operator=(HasPtr rhs);
//can use the above copy and swap method, or the two separate assignment operators below:
  HasPtr &operator=(const HasPtr &rhs);
  HasPtr &operator=(HasPtr&& rhs);

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