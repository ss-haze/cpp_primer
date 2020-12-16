#include <iostream>
#include <vector>
#include <string>

using std::string; using std::vector; using std::cin; using std::cout;

int main()
{

	// calculate sum of two adjacent vector elements
	vector<int> v1;
	int x = 0;

	for (int x = 0; cin >> x; v1.push_back(x));

	if (v1.size() == 1 || v1.empty())
	{
		std::cerr << "Error: Vector must contain at least two elements";
		return -1;
	}

	for (auto it=v1.begin(); it < v1.end()-1; ++it)
	{
		cout << (*it + *(it+1)) << " ";
	}

	/*calculate sum of first and last vector elements, followed by sum of second and second-to-last elements, and so on*/
	cout << "\n";
	for (auto b=v1.begin(), e=v1.end()-1; b<=e; b++, e--)
	{
		cout << *b + *e << " ";
	}

	return 0;
}