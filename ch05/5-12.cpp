#include <iostream>
#include <string>

using std::string; using std::cout; using std::cin;

string total_is_one_test(const int& total)
{
	if (total == 1)return "";
	else return "s";
}

int main() {

	char input, previousChar ='\0';
	string pff_string, fl_string, fi_string;
	unsigned a_cnt = 0, e_cnt = 0, i_cnt = 0, o_cnt = 0, u_cnt = 0, 
		space_cnt=0, newLine_cnt=0, tab_cnt=0, sequence_cnt_ff=0, sequence_cnt_fi = 0, sequence_cnt_fl = 0;

	while (cin >>std::noskipws>>input)
	{
			switch (input)
			{
				case ('a'): case ('A'):
					++a_cnt;
					break;

				case ('e'): case ('E'):
					++e_cnt;
					break;

				case ('i'): 
					++i_cnt;
					if (previousChar == 'f')
					{
						++sequence_cnt_fi;
					}
					break;

				case ('I'):
					++i_cnt;	
					break;

				case ('o'): case ('O'):
					++o_cnt;
					break;

				case ('u'): case ('U'):
					++u_cnt;
					break;

				case (' '):
					++space_cnt;
					break;

				case ('\n'):
					++newLine_cnt;
					break;

				case ('\t'):
					++tab_cnt;
					break;

				case ('f'):
					if (previousChar == 'f')
					{
						++sequence_cnt_ff;
					}
					break;	

				case('l'):
					if (previousChar == 'f')
					{
						++sequence_cnt_fl;
					}

				default:
					;
			}
			previousChar = input;
	}

	cout << "'a' occured " << a_cnt << " time" << total_is_one_test(a_cnt) << std::endl;
	cout << "'e' occured " << e_cnt << " time" << total_is_one_test(e_cnt) << std::endl;
	cout << "'i' occured " << i_cnt << " time" << total_is_one_test(i_cnt) << std::endl;
	cout << "'o' occured " << o_cnt << " time" << total_is_one_test(o_cnt) << std::endl;
	cout << "'u' occured " << u_cnt << " time" << total_is_one_test(u_cnt) << std::endl;
	cout << "' ' occured " << space_cnt << " time" << total_is_one_test(space_cnt) << std::endl;
	cout << "'\\t' occured " << tab_cnt << " time" << total_is_one_test(tab_cnt) << std::endl;
	cout << "'\\n' occured " << newLine_cnt << " time" << total_is_one_test(newLine_cnt) << std::endl;
	cout << "'ff' occured " << sequence_cnt_ff << " time" << total_is_one_test(sequence_cnt_ff) << std::endl;
	cout << "'fi' occured " <<  sequence_cnt_fi<< " time" << total_is_one_test(sequence_cnt_fi) << std::endl;
	cout << "'fl' occured " << sequence_cnt_fl << " time" << total_is_one_test(sequence_cnt_fl) << std::endl;

	return 0;
}