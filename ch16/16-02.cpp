#include <iostream>
#include <functional>
#include <string>

using std::cout;
using std::endl;
using std::less;
using std::string;

template <typename T>
int compare(const T &v1, const T &v2)
{
  if (less<T>()(v1, v2))
    return -1;
  if (less<T>()(v2, v1))
    return 1;
  return 0;
}

int main()
{
  cout << compare(4, 5) << endl;
  cout << compare(5, 4) << endl;
  cout << compare(4, 4) << endl  << endl;

  string s1("yes"), s2("no");
  cout << compare(s1, s2) << endl;
  cout << compare(s2, s1) << endl;
  cout << compare(s1, s1) << endl << endl;
  return 0;
}