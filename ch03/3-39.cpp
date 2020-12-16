#include <iostream>
#include <string>
#include <cstring>

using std::cout; using std::string;

int main ()
{
	//comapre two strings
	string s1{ "hello there"}, s2{ "hello there" };
	if (s1 == s2) cout << "The strings are identical\n";
	else if (s1.size() == s2.size()) cout << "The strings have equal length but contain different characters\n";
	else cout << "The strings are of different length\n";


	//compare two c-style strings using strcmp and strlen
	const char c1[] = "Character string", c2[] = "Character string";
	if (strcmp(c1, c2) == 0) cout << "The c-style strings are the identical\n";
	else if (strlen(c1) == strlen(c2)) cout << "The c-style strings have equal length but contain different characters\n";
		else cout <<"The c-style strings are of different length\n";


	//compare two c-style strings using pointers
	size_t Length_c1 = 0, Length_c2 = 0;
	for (const char* b = c1; *b != '\0'; ++b, ++Length_c1);
	for (const char* b = c2; *b != '\0'; ++b, ++Length_c2);

	if (Length_c1 == Length_c2)
	{
		const char* pc1 = c1, * pc2 = c2;
		for (; *pc1 != '\0' && *pc1==*pc2; ++pc1, ++pc2);
		if (*pc1 == '\0') cout << "The c-style strings are identical";
		else cout << "The c-style strings are of similar length but contain differenct characters";
	}
	else cout << "The c-style strings are of different length";

	return 0;
}