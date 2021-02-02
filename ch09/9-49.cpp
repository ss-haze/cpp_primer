#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;

void compare(string &para, string &largest, const string &test)
{
  string::size_type pos = 0;
  istringstream is;
  string word;

  for (is.str(para); is >> word;)
  {
    pos = word.find_first_of(test);
    if (pos == string::npos && word.size() > largest.size())
      largest = word;
  }
}

int main()
{
  const string ifile = "input.txt";
  string test = "bdfghjklpqty", largest, para;

  for (ifstream is(ifile); getline(is, para); compare(para, largest, test))
    ;
  cout << "The largest word containing no ascenders nor descenders was " << largest;

  return 0;
}
