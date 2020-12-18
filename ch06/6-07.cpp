#include <iostream>
using std::cout;
using std::endl;

size_t count() //x is a parameter
{
	static size_t cnt = 0; //cnt is local static variable
	return cnt++;
}

int main()
{
	for (auto i = 0; i != 10; i++) //i is a local variable
		cout << "count stands at :" << count() << endl;

	return 0;
}