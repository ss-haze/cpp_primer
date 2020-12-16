#include <iostream>
#include <vector>
#include <string>

using std::vector; using std::cout;  
using std::cin; using std::endl; using std::string;

int main()
{
	vector<string> vs;
	string input;
	while (cin >> input) vs.push_back(input);
	for (auto& c : vs) cout << c << endl;

	return 0;
}