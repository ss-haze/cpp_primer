#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

inline bool isShorter(const string &s1, const string &s2)
{
  return s1.size() < s2.size();
}

int main()
{
  string s1 = "hello", s2 = "bye";
  cout << isShorter(s1, s2) << endl;

  return 0;
}