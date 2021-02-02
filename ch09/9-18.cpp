#include <deque>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::deque;
using std::string;

int main()
{
  deque<string> ds;

  for (string input; cin >> input; ds.push_back(input))
    ;

  for (auto b = ds.cbegin(), e = ds.cend(); b != e; ++b)
    cout << *b << " ";

  return 0;
}
