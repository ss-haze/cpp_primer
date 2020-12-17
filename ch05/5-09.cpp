#include <iostream>	
#include <string>

using std::cin; using std::cout; using std::string;

string total_is_one_test(const int& total)
{
	if (total ==1) return "";
	else return "s";
}

int main() {

	string input; unsigned a_cnt=0, e_cnt=0, i_cnt=0, o_cnt=0, u_cnt=0;
	while (std::getline(cin, input))
	{
		for (const auto& c : input)
		{
			if (c == 'a') ++a_cnt;
			else if (c == 'e') ++e_cnt;
			else if (c == 'i') ++i_cnt;
			else if (c == 'o') ++o_cnt;
			else if (c == 'u') ++u_cnt;
		}
	}

	cout << "'a' occured " << a_cnt << " time" << total_is_one_test(a_cnt)<<std::endl;
	cout << "'e' occured " << e_cnt << " time" << total_is_one_test(e_cnt)<<std::endl;
	cout << "'i' occured " << i_cnt << " time" << total_is_one_test(i_cnt)<<std::endl;
	cout << "'o' occured " << o_cnt << " time" << total_is_one_test(o_cnt)<<std::endl;
	cout << "'u' occured " << u_cnt << " time" << total_is_one_test(u_cnt)<<std::endl;

	return 0;
}