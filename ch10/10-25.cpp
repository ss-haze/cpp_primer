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

void elimDuplicates(vector<string> &vec)
{
  std::sort(vec.begin(), vec.end());
  auto cutoff = std::unique(vec.begin(), vec.end());
  vec.erase(cutoff, vec.end());
}

bool checkSize(const string &s, vector<string>::size_type sz)
{
  return s.size() < sz;
}

void biggies(vector<string> &v, const vector<string>::size_type sz)
{
  elimDuplicates(v);

  std::stable_sort(v.begin(), v.end(), [](const string &s1, const string &s2) { return s1.size() < s2.size(); });

  auto cutoff = std::partition(v.begin(), v.end(), bind(checkSize, _1, sz));

  std::for_each(v.begin(), v.end(), [&sz](const string s) { cout << (s.size() >= sz ? s + " " : ""); });
}

int main()
{
  vector<string> initial{"the", "quick", "zany", "brown", "fox", "dog", "jumped", "over", "the", "dozing", "blue", "dog"};
  biggies(initial, 5);
  return 0;
}