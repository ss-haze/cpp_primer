#include <iostream>

using std::cin;
using std::cout;

int main()
{
  int a;
  auto sum = [a](int b) -> int { return a + b; };

  cout << "Please enter an integer value, which will be added to 10 : ";
  cin >> a;

  cout << "The resultant sum is: " << sum(10);

  return 0;
}