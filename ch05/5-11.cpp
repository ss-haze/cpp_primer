#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

string total_is_one_test(const int &total)
{
  if (total == 1)
    return "";
  else
    return "s";
}

int main()
{

  char input;
  unsigned a_cnt = 0, e_cnt = 0, i_cnt = 0, o_cnt = 0, u_cnt = 0,
           space_cnt = 0, newLine_cnt = 0, tab_cnt = 0;

  while (cin >> std::noskipws >> input)
  {
    switch (input)
    {
    case ('a'):
    case ('A'):
      ++a_cnt;
      break;

    case ('e'):
    case ('E'):
      ++e_cnt;
      break;

    case ('i'):
    case ('I'):
      ++i_cnt;
      break;

    case ('o'):
    case ('O'):
      ++o_cnt;
      break;

    case ('u'):
    case ('U'):
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

    default:;
    }
  }

  cout << "'a' occured " << a_cnt << " time" << total_is_one_test(a_cnt) << std::endl;
  cout << "'e' occured " << e_cnt << " time" << total_is_one_test(e_cnt) << std::endl;
  cout << "'i' occured " << i_cnt << " time" << total_is_one_test(i_cnt) << std::endl;
  cout << "'o' occured " << o_cnt << " time" << total_is_one_test(o_cnt) << std::endl;
  cout << "'u' occured " << u_cnt << " time" << total_is_one_test(u_cnt) << std::endl;
  cout << "' ' occured " << space_cnt << " time" << total_is_one_test(space_cnt) << std::endl;
  cout << "'\\t' occured " << tab_cnt << " time" << total_is_one_test(tab_cnt) << std::endl;
  cout << "'\\n' occured " << newLine_cnt << " time" << total_is_one_test(newLine_cnt) << std::endl;

  return 0;
}