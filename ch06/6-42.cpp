#include <iostream>
#include <string>

using std::cout;
using std::string;

string make_plural(const size_t ctr, const string &word, const string &ending = "s")
{
  return (ctr > 1) ? word + ending : word;
}

int main()
{
  string s1 = "failure";
  string s2 = "success";
  cout << make_plural(1, s1) << std::endl;
  cout << make_plural(10, s1) << std::endl;
  cout << make_plural(1, s2, "es") << std::endl;
  cout << make_plural(10, s2, "es") << std::endl;

  return 0;
}