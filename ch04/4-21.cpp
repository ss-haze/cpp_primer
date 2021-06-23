
#include <string>
#include <vector>
#include <iostream>

using std::string; using std::vector;

int main() {

	vector<int> vi = { 1,2,3,4,5,6,7,8,9,10 };

	for (auto& i : vi) i % 2 ? i*=2 : i;

	for (const auto& i : vi) std::cout << i << " ";

	return 0;
}