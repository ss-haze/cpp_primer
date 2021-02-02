#include <iostream>
#include <stack>
#include <string>

using std::cout;
using std::stack;
using std::string;

int main()
{

  string open("{[("), close("}])");
  string input("(Here is a {test (string) for } the program)");
  stack<char> stk;
  bool symmetry = true;

  for (const auto &c : input)
  {
    if (open.find(c) != string::npos)
    {
      stk.push(c);
      continue;
    }

    if (close.find(c) != string::npos && stk.empty())
    {
      symmetry = false;
      break;
    }

    if (close.find(c) != string::npos && !stk.empty())
    {
      if (close.find(c) != open.find(stk.top()))
      {
        symmetry = false;
        break;
      }
      else
        stk.pop();
    }
  }

  cout << (symmetry && stk.empty() ? "The parentheses match" : "The parentheses do not match");

  return 0;
}
