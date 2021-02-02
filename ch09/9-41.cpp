#include <vector>
#include <string>
#include <iostream>

using std::cout;
using std::string;
using std::vector;

int main()
{

  vector<char> vc{'h', 'e', 'l', 'l', 'o'};

  string s(vc.begin(), vc.end());

  cout << s;

  return 0;
}