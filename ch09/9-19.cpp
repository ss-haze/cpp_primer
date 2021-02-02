#include <list>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::list;
using std::string;

int main()
{
  list<string> ls;

  for (string input; cin >> input; ls.push_back(input))
    ;

  for (auto b = ls.cbegin(), e = ls.cend(); b != e; ++b)
    cout << *b << " ";

  return 0;
}