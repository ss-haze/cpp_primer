#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using std::cout; using std::cin; using std::vector;

int main()
{
	const size_t x = 10;
	int arr[x];

	for (size_t i = 0; i != x; ++i) arr[i] = i;

	for (const auto & c : arr) cout << c << " ";

	int arr2[x];
	for (size_t i = 0; i != x; arr2[i] = arr[i], ++i);
	cout << "\n";
	for (const auto & c : arr2) cout << c << " ";

	vector<int> v;
	vector<int> v2;
	cout << "\n";

	for (vector<int>::size_type i = 0; i != 10; v.push_back(i++));
	for (const auto & i : v) cout << i << " ";
	v2 = v;
	cout << "\n";
	for (const auto & i : v2) cout << i << " ";

	return 0;
}