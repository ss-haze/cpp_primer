#include <iostream>
#include <vector>
#include <string>

using std::string; using std::vector; using std::cin; using std::cout;

int main()
{
	vector<string> vs;
	string s;

	while (cin >> s)
	{
		vs.push_back(s);
	}

	for (auto& c : vs)
	{
		for (auto& c1 : c) c1 = toupper(c1);
	}

	for (decltype (vs.size()) i = 0; i != vs.size(); ++i)
	{
		cout << vs[i];
		((i+1) % 8 == 0) ? cout << "\n" : cout << " ";
	}

	return 0;
}