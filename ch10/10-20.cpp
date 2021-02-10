#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

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

void biggies(vector<string> &v, const vector<string>::size_type sz)
{
  elimDuplicates(v);

  auto count = std::count_if(v.begin(), v.end(), [sz](const string &s) { return s.size() > sz; });

  cout << count << " " << make_plural(count, "word", "s") << " of length greater than 6 were found";
}

int main()
{
  vector<string> initial;
  for (string input; std::cin >> input; initial.push_back(input))
    ;

  biggies(initial, 6);

  return 0;
}