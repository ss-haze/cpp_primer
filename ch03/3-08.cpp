#include <iostream>
#include <string>

using std::string; using std::cout; using std::endl;

int main()
{
	string s = "hello";
	decltype(s.size()) n = 0;

	while (n < s.size())
	{
		s[n] = 'X';
		++n;
	}
	cout << s << endl;

	s = "goodbye";
	for (decltype(s.size()) n = 0; n < s.size(); s[n++] = 'X');
	cout << s << endl;

  //The ranged for is easier to write than the while and the traditional for.

	return 0;
}