#include <iostream>
#include <string>

class DebugDelete
{
public:
  DebugDelete(std::ostream &os_ = std::cerr) : os(os_) {}
  template <typename T>
  void operator()(T *p) const
  {
    os << "deleting unique_ptr" << '\n';
    delete p;
  }

private:
  std::ostream &os;
};

