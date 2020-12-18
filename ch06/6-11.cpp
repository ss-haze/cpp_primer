#include <iostream>

using std::cout;
using std::endl;

int reset(int &i)
{
  return (i = 0);
}

int main()
{
  int i = 100;
  std::cout << reset(i);
  return 0;
}