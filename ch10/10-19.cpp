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

void biggies(vector<string> &v, const vector<string>::size_type sz)
{
  elimDuplicates(v);

  std::stable_sort(v.begin(), v.end(), [](const string &s1, const string &s2) { return s1.size() < s2.size(); });

  auto cutoff = std::stable_partition(v.begin(), v.end(), [sz](const string &s) { return s.size() >= sz; });

  std::for_each(v.begin(), cutoff, [](const string s) { cout << s << " "; });
}

int main()
{
  vector<string> initial{"the", "quick", "zany", "brown", "fox", "dog", "jumped", "over", "the", "dozing", "blue", "dog"};
  biggies(initial, 4);
  return 0;
}