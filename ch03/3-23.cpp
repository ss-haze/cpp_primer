#include <iostream>
#include <vector>
#include <string>

using std::string; using std::vector; using std::cin; using std::cout;

int main()
{
	vector<int> vi{ 1,2,3,4,5,6,7,8,9,10 };
	for (auto it = vi.begin(); it != vi.end(); *it *= 2, ++it);
	for (const auto& i : vi) cout << i << " ";
	return 0;
}