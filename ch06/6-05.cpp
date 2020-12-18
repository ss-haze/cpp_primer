#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int absolute(int x)
{
	return x < 1 ? -x : x;
}

int main()
{
	vector<int> v{1, 2, 3, 4, 5, -6, -7, -8, -9};
	for (auto i : v)
		cout << absolute(i) << " ";

	return 0;
}