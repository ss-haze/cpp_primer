#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{

  string repeat;

  do
  {
    string s1, s2;
    cout << "\nPlease input string s1: ";
    std::cin >> s1;
    cout << "Please input string s2: ";
    std::cin >> s2;

    if (s1 == s2)
      cout << "\nThe strings are the same\n\nDo you wish to repeat (y/n)? ";
    else
      cout << (s1 < s2 ? "\"" + s1 + "\"" : "\"" + s2 + "\"") << " is the lesser string\n\n"
           << "Do you wish to repeat (y/n)? ";
    std::cin >> repeat;
  } while (repeat[0] == 'y');

  return 0;
}