#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>

using std::cout;
using std::string;
using std::vector;
using std::bind;
using std::placeholders::_1;

void elimDuplicates(vector<string> &vec)
{
  std::sort(vec.begin(), vec.end());
  auto cutoff = std::unique(vec.begin(), vec.end());
  vec.erase(cutoff, vec.end());
}

string make_plural(size_t c, const string &s, const string &end)
{
  return (c == 1 ? s : s + end);
}

bool checkStringLength (const string& s, vector<string>::size_type sz)
{
  return s.size() >sz;
}

void biggies(vector<string> &v, const vector<string>::size_type sz)
{
  elimDuplicates(v);

  auto count = std::count_if(v.begin(), v.end(), bind(checkStringLength, _1, sz) );

  cout << count << " " << make_plural(count, "word", "s") << " of length greater than "<< sz<< " were found";
}

int main()
{
  vector<string> initial;
  for (string input; std::cin >> input; initial.push_back(input))
    ;

  biggies(initial, 6);

  return 0;
}