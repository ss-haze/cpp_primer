#include <string>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  string cur_str, pre_str, lgst_str;
  unsigned curr_cnt = 0, lgst_cnt = 0;

  while (cin >> cur_str)
  {
    if (cur_str == pre_str)
      ++curr_cnt;
    else if (curr_cnt > lgst_cnt)
    {
      lgst_cnt = curr_cnt;
      lgst_str = pre_str;
    }
    pre_str = cur_str;
  }

  if (curr_cnt > lgst_cnt)
  {
    lgst_cnt = curr_cnt;
    lgst_str = pre_str;
  }

  if (lgst_cnt > 0)
    cout << "The word " << lgst_str << " was repeated " << lgst_cnt << " times\n";
  else
    cout << "No word was repeated\n";

  return 0;
}