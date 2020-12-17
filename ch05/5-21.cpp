#include <string>
#include <iostream>

using std::string; using std::cout; using std::cin; using std::endl;

int main()
{
	string current, previous;
	bool repeat = false; int cnt = 0;

	while (cin >> current)
	{
		if (!isupper(current[0])) continue;
		if (current == previous)
		{
			++cnt;
			if (cnt == 2) {
				repeat = true;
				break;
			}
		}
		else previous = current;
	}

	if (!repeat) cout << "No word starting with a capital letter was repeated twice \n";
	else cout << "\"" << current << "\"" << " was repeated twice";

	return 0;
}