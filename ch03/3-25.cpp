#include <iostream>
#include <vector>
#include <string>

using std::string; using std::vector; using std::cin; using std::cout;

int main()
{
	vector<int>grades(11, 0);

	for (int input; cin >> input;)
	{
		if (input <= 100 && input >=0)
		{
			++*(grades.begin() + input / 10);
		}
		else std::cerr << input << ": Error: an input was out of range and ignored\n";
	}

	for (const auto & i : grades) cout << i << " ";
  
	return 0;
}