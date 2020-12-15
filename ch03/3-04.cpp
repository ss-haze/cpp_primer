#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
  string s1, s2;

  std::cin >> s1 >> s2;

  if (s1 == s2)
    cout << "The strings are identical\n";
  else
  {
    if (s1 < s2)
      cout << "The second string is larger than The first\n";
    else
      cout << "The first string is larger than the second\n";

    if (s1.length() == s2.length())
      cout << "The strings are of equal length\n";
    else
    {
      if (s1.length() > s2.length())
        cout << "The first string is longer than the second";
      else
        cout << "The second string is longer than the first";
    }
  }
}