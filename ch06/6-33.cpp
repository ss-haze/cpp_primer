#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::string;
using std::vector;
using Iterator = const vector<string>::const_iterator;

auto print(Iterator &b, Iterator &e) -> void
{
  if (b == e)
    return;
  cout << *b << " ";
  print(b + 1, e);
}

int main()
{
  const vector<string> v{"hello", "bye", "yes", "no", "maybe"};
  print(v.begin(), v.end());

  return 0;
}