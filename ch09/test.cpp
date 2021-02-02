#include <vector>
#include <iostream>

using std::cout;
using std::string;
using std::vector;

int main()
{
  string s = "hello2ghtj4gjk0kjk", numbers = "0123456789";

  for (string::size_type pos = 0; (pos = s.find_first_of(numbers, pos)) != string::npos; ++pos)
    cout << "Number found at position: " << pos << " Element is: " << s[pos] << std::endl;

vector<int> v = {1,2,3,4,5};

    vector<int>::iterator::difference_type diff = v.end() - v.begin();

    cout << diff;

  return 0;
}