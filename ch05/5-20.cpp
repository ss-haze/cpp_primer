#include <string>
#include <iostream>

using std::string; using std::cout; using std::cin; using std::endl;

int main()
{
	string current, previous;
	int cnt = 0; bool repeat = false;

	while (cin >> current)
	{
		if (current == previous)
		{
			++cnt;
			if (cnt == 2) {
				repeat = true;
				break;
			}
		}
		else
		{
			previous = current;
			cnt = 0;
		}
	}
		
	if (!repeat) cout << "No word was repeated twice\n";
	else cout <<"\"" << current << "\"" << " was repeated twice";

	return 0;
}