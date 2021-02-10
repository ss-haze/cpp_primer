#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::vector; using std::string;

bool isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}

void print(const std::vector<string>& v)
{
	for (const auto& s : v) std::cout << s << " ";
	std::cout << std::endl;
}

void elimDups(vector<string>& vec)
{
	std::stable_sort(vec.begin(), vec.end(), isShorter);
	print(vec);

	std::unique(vec.begin(), vec.end());
	print(vec);
}

int main()
{
	vector<string> vs{ "It", "is", "a", "beautiful", "and", "a", "sunny", "day", "is", "it", "not?" };
	print(vs); 
	elimDups(vs);

	return 0;
}