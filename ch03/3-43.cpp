#include <iostream>
#include <iterator>

using std::cout; using std::begin; using std::end;

int main()
{
	int ia[3][4] = { {0,1,2,3}, {4,5,6,7}, {8, 9,10,11} };

	//using range for
	for (const int (&it)[4] : ia)
	{
		for (const int &it2 : it)
			cout << it2 << " ";
	}
	cout << '\n';

	//using subscripts
	for (size_t i = 0; i != 3; ++i)
	{
		for (size_t j = 0; j != 4; ++j)
			cout << ia[i][j]<<" ";
	}
	cout << '\n';

	//using pointers
	for (int(*p)[4] = ia; p != ia + 3; ++p)
	{
		for (int* q = *p; q!=*p+4;++q)
			cout << *q << " ";
	}
	cout << '\n';

	//using iterators
	for (int(*p)[4] = begin(ia); p != end(ia); ++p)
	{
		for (int * q= begin(*p); q!=end(*p); ++q)
			cout << *q << " ";
	}

	return 0;
}