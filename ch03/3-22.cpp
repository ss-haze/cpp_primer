#include <iostream>
#include <vector>
#include <string>


using std::string; using std::vector; using std::cin; using std::cout;

int main()
{

	vector<string> text;
	for (string input; getline(cin, input); text.push_back(input));

	if (text.empty())
	{
		std::cerr << "Error: No input";
		return -1;
	}

	auto it = text.begin();

	for (; it != text.end() && it->empty(); ++it);

	if (it == text.end())
	{
		std::cerr << "Error: input was all empty strings";
		return -1;
	}

	for (auto& c : *it) c = (islower(c) ? toupper(c) : c);
	for (const auto& para : text)
	{
		if (!para.empty()) cout << para << '\n';
	}

	return 0;
}