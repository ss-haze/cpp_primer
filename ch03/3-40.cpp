#include <iostream>
#include <cstring>

using std::cout; 


int main()
{
  const char c1[] = "First string";
	const char c2[] = "Second string";
	char c3[27];

	strcpy(c3, c1);
	strcat(c3, " ");
	strcat(c3, c2);

	cout << c3<<'\n';

return 0;
}