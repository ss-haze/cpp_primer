#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
  for (int a = 0, b = 0; cout << "please input two integers: ", cin >> a >> b;)
  {
    try
    {
      if (b == 0)
        throw runtime_error("Cannot divide by zero\n");
      cout << a / b << endl;
    }
    catch (runtime_error err)
    {
      cout << err.what() << "Try again? (y/n) ";
      char c;
      cin >> c;
      if (c == 'n' || !cin)
        break;
    }
  }

  return 0;
}