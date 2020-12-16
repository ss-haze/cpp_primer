#include <iostream>

using std::cout; using std::cin;

int main()
{
	const size_t x = 10;
	int arr[x];

	for (size_t i = 0; i != x; ++i) arr[i] = i;

	for (auto c : arr) cout << c << " ";

	return 0;
}