#include <iostream>

using std::cout;
using std::endl;

int fact(int x)
{
	try
	{
		if (x < 0)
			throw std::runtime_error("Error: Input cannot be a negative number");
		if (x == 1 || x == 0)
			return 1;
		else
			return x * fact(x - 1);
	}
	catch (std::runtime_error err)
	{
		cout << err.what();
	}
}

int main()
{
	for (int i = 1; i < 11; ++i)
		cout << i << "! is " << fact(i) << endl;
	return 0;
}