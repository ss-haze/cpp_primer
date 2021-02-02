#include <string>
#include <iostream>

using std::cout;
using std::string;

string &replace_string(string &s, const string &oldVal, const string &newVal)
{
  for (auto b = s.begin(); b <= s.end() - oldVal.size();)
  {
    if (oldVal == string (b, b+oldVal.size())  )
    {
      b = s.erase(b, b+oldVal.size());
      b = s.insert(b, newVal.begin(), newVal.end());
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