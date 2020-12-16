#include <iostream>
#include <vector>

using std::vector; using std::cout;  using std::cin; using std::endl;

int main()
{
	vector<int> vi;
	int input;
	while (cin >> input) vi.push_back(input);
	for (auto& c : vi) cout << c << endl;

	return 0;
}