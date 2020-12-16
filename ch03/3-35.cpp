#include <iostream>
#include <iterator>

using std::cout; using std::begin; using std::end;

int main()
{
	int arr [] = { 1,2,3,4,5,6,7,8,9 };
  for (auto i : arr) cout << i << " "; cout <<'\n';

	for (int* b = begin(arr), *e = end(arr); b != e; *b++ = 0);
  
	for (auto i : arr) cout << i << " ";

	return 0;
}