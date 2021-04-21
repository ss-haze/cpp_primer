#include <cstring>
#include <iostream>
#include <functional>

using namespace ::std;

int main()
{
  plus<int> intAdd;
  int sum = intAdd(1, 2);
  cout << sum;
  return 0;
}