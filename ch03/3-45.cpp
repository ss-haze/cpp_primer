#include <iostream>
#include <iterator>

using std::cout; using std::begin; using std::end;

int main()
{
	int ia[3][4] = { {0,1,2,3}, {4,5,6,7}, {8, 9,10,11} };

	//using range for and type alias
	for (const auto &it : ia)
	{
		for (const auto& it2 : it)
			cout << it2 << " ";
	}
	cout << '\n';

	//using subscripts
	for (size_t i = 0; i != 3; ++i)
	{
		for (size_t j = 0; j != 4; ++j)
			cout << ia[i][j] << " ";
	}
	cout << '\n';

	//using pointers and type alias
	for (const auto *p = ia; p != ia + 3; ++p)
	{
		for (const auto* q = *p; q != *p + 4; ++q)
			cout << *q << " ";
	}
	cout << '\n';

	//using iterators and type alias
	for (auto p = begin(ia); p != end(ia); ++p)
	{
		for (auto q = begin(*p); q != end(*p); ++q)
			cout << *q << " ";
	}

	return 0;
}