#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int largest_value(const int &x, const int *const p)
{
  return x < *p ? *p : x;
}

int main()
{
  int a = 10, b = 5, c = 20;

  cout << largest_value(a, &b) << endl;
  cout << largest_value(b, &c) << endl;

  return 0;
}