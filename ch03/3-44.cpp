#include <iostream>
#include <iterator>

using std::cout; using std::begin; using std::end;

int main()
{
	int ia[3][4] = { {0,1,2,3}, {4,5,6,7}, {8, 9,10,11} };

	using int_ref = int[4];

	//using range for and type alias
	for (const int_ref &it : ia)
	{
		for (const int& it2 : it)
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
	for (const int_ref *p = ia; p != ia + 3; ++p)
	{
		for (const int* q = *p; q != *p + 4; ++q)
			cout << *q << " ";
	}
	cout << '\n';

	//using iterators and type alias
	for (const int_ref *p = begin(ia); p != end(ia); ++p)
	{
		for (const int* q = begin(*p); q != end(*p); ++q)
			cout << *q << " ";
	}

	return 0;
}