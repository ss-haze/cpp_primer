#include <iostream>
#include <string>

using std::string; using std::cout; using std::endl; using std::cin;

int main()
{
	string input;
  while (getline (cin, input))
  {
    for (auto &c : input)
      if (!ispunct(c)) cout << c;
  }
	return 0;
}