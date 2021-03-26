#include <iostream>
#include <string>
#include <vector>

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
  std::vector<string> vs;

  for (string temp; !(temp = ps()).empty(); vs.push_back(temp))
    ;

  for (const auto &s : vs)
    std::cout << s << " ";
  return 0;
}