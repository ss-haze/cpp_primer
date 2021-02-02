#include <iostream>
#include <vector>
#include <string>

using std::vector; using std::cout; using std::string;

int vec_string_to_int(const vector<string> & v)
{
	int sum = 0;
	for (const auto& i : v)
		sum += std::stoi(i);
	return sum;
}

float vec_string_to_float(const vector<string>& v)
{
	float sum = 0.0;
	for (const auto& i : v)
		sum += std::stof(i);
	return sum;
}

int main() {

	vector<string> s{ "1", "2","3", "4","5","6","7","8","9" };

	cout << vec_string_to_int(s) << std::endl;
	cout << vec_string_to_float(s) << std::endl;
  
	return 0;
}