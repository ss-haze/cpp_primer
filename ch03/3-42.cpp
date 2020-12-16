#include <iostream>
#include <vector>
#include <iterator>

using std::cout; using std::vector; using std::begin; using std::end;

int main()
{
	vector <int> v2{ 0,1,2,3,4,5,6 };
	int a2[7];
  
	auto b = v2.begin();
	for (size_t i = 0; b != v2.end(); a2[i++] = *b++);
	for (const auto &i : a2) cout << i << " ";

	return 0;
}