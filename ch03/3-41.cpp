#include <iostream>
#include <vector>
#include <iterator>

using std::cout; using std::string; using std::vector;

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9};

	vector<int> v(std::begin(arr), std::end(arr));
	for (const auto &i : v) cout << i << " ";

	return 0;
}