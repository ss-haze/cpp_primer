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

	for (decltype(v1.size()) i = 0; i < v1.size() - 1; ++i)
	{
		cout << (v1[i] + v1[i + 1]) << " ";
	}

	//calculate sum of first and last vector elements, followed by sum of second and second-to-last elements, and so on
	cout << "\n";
	auto halfWay = (v1.size() + 1) / 2;
	for (decltype(v1.size()) start = 0; start != halfWay; ++start)
	{
		cout << v1[start] + v1[v1.size()-1-start]<<" ";
	}
	
	return 0;
}