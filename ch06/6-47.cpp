#define NDEBUG
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

int cnt = 0;

using std::cout;
using std::string;
using std::vector;

using Iterator = const vector<string>::const_iterator;

void print(Iterator &b, Iterator &e)
{
  if (b == e)
    return;
  cout << *b << std::endl;

  assert(++cnt);

#ifndef NDEBUG
  cout << __FILE__ << " The size of the vector is currently " << e - b << std::endl;
#endif

  print(b + 1, e);
}

int main()
{
  const vector<string> v{"hello", "bye", "yes", "no", "maybe"};
  print(v.begin(), v.end());
  cout << "\nIf NDEBUG is defined cnt should finish at 0. cnt finished at " << cnt << std::endl;

  return 0;
}