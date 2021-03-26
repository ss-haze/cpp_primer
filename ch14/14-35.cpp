#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;

class PrintString
{
public:
  PrintString(istream &is = std::cin)
      : is_(is)
  {
  }
  string operator()() const
  {
    string s;
    std::getline(is_, s);
    return is_ ? s : string();
  }

private:
  istream &is_;
};

int main()
{
  PrintString ps;
  std::cout << ps() << std::endl;
  std::cout << PrintString()();
  return 0;
}
