#include <iostream>
#include <string>

using std::string; using std::cout; using std::cin;

int main()
{
  for (string s; cout <<"\nPlease enter a string: ", cin >>s;)
  {
    for (char &c : s) c = 'X';
	  cout << s ;
  }

	return 0;
}