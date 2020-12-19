#include <string>
#include <iostream>

using std::cout;
using std::string;

bool contains_capital_letters(const string &s)
{
	for (const auto &c : s)
		if (isupper(c))
			return true;
	return false;
}

void change_to_lowercase(string &s)
{
	for (auto &c : s)
		//if (isupper(c)) c = tolower(c);
		if (c >= 65 && c <= 90)
			c += 'a' - 'A';
}

//parameter for first function is const because we are not changing the argument
//whereas we are changing the argument in the second function

int main()
{
	string s1 = "no capitals", s2 = "has a Capital", s3 = "Lower AND UpperCase";
	contains_capital_letters(s1) ? cout << "s1 contains capital letters\n" : cout << "s1 does not contain capital letters\n";
	contains_capital_letters(s2) ? cout << "s2 contains capital letters\n" : cout << "s2 does not contain letters\n";
	change_to_lowercase(s3);
	cout << s3;

	return 0;
}