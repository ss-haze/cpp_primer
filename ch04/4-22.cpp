#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::string;
using std::vector;

int main()
{

  vector<int> vi{55, 78, 64, 89, 96, 20};

  //using conditional operators
  for (const auto &grade : vi)
  {
    cout << (grade > 90 ? "high pass"
                        : grade < 60 ? "fail"
                                     : grade > 75 ? "pass"
                                                  : "low pass")
         << " ";
  }
  cout << '\n';

  //using for loops
  for (auto grade : vi)
  {
    if (grade > 90)
      cout << "high pass"
           << " ";
    else if (grade < 60)
      cout << "fail"
           << " ";
    else if (grade > 75)
      cout << "pass"
           << " ";
    else
      cout << "low pass"
           << " ";
  }

  string s = "word";
  s + s[s.size() - 1] == 's';

  return 0;
}

//the version using if is easier to understand; the conditional operator becomes more difficult to read when nested.