#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>

using std::bind;
using std::cout;
using std::string;
using std::vector;
using std::placeholders::_1;

bool checkSize(const string &s, vector<string>::size_type sz)
{
  return s.size() < sz;
}

int main()
{
  vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  string test = "yes";

  auto it = std::find_if(vec.begin(), vec.end(), bind(checkSize, test, _1));

  if (it != vec.end())
    cout << "The first value greater than the string size is " << *it;
  else
    cout << "No value was found";

  return 0;
}