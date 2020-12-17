#include <vector>
#include <string>
#include <iostream>

using std::vector; using std::cin; using std::cout; using std::endl;

int main() {

	vector<int> grades;
	vector<std::string> scores = { "F", "D", "C", "B", "A", "A+" };
	int grade;

	for (; cin >> grade; grades.push_back(grade));

	for (const auto & i : grades)
	{
		std::string result;
		if (i < 60) result = scores[0];
		else
		{
			result = scores[i / 10 - 5];
			if (i != 100)
			{
				result += (i % 10 < 4) ? "-" : (i % 10 > 6 && i < 90) ? "+" : "";
			}
		}

		cout << "Grade " << i << " scored " << result << endl;
	}

	return 0;
}