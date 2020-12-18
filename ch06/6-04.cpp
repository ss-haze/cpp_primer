#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int fact(int x)
{
	return x > 1 ? x * fact(x - 1) : 1;
}

int main()
{
	try
	{
		int input = 0;
		cout << "Please input a number for which the factorial will be derived: ";
		cin >> input;
		if (input < 0 || input > 20)
			throw "Input is out of range";
		cout << input << "! is " << fact(input) << endl;
		return 0;
	}
	catch (const char *msg)
	{
		std::cerr << msg << endl;
		return 1;
	}
	return 0;
}