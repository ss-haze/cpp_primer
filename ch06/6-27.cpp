#include <iostream>
#include <initializer_list>

using std::cout; using std::initializer_list;

int sum(initializer_list<int> & int_list)
{
	size_t sum = 0;
	for (auto & e : int_list) sum += e;
	return sum;
}

int main()
{
	cout << sum({ 1,2,3,4,5,6,7,8,9,10 });

	return 0;
}