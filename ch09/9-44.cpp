#include <string>
#include <iostream>

using std::cout;
using std::string;

string &replace_string(string &s, const string &oldVal, const string &newVal)
{
  for (size_t b = 0; b <= s.size() - oldVal.size();)
  {
    if (oldVal == string (s, b, b+oldVal.size())  )
    {
      s.replace(b, oldVal.size(), newVal);
      b += newVal.size();
    }
    else ++b;
  }

  return s;
}

int main()
{
  string s = "tho tired, and tho overworked, I shall work thru", oldVal = "tho", newVal = "though";

  cout << replace_string(s, oldVal, newVal) << std::endl;

  oldVal = "thru";
  newVal = "through";

  cout << replace_string(s, oldVal, newVal) << std::endl;

  return 0;
}