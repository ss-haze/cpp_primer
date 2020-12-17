#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
  int a = 0, b = 0;

  cin >> a >> b;
  if (b == 0)
    throw runtime_error("Cannot divide by zero");
  cout << a / b << endl;

  return 0;
}