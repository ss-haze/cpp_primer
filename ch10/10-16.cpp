#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;

void elimDuplicates(vector<string> &vec)
{
  std::sort (vec.begin(), vec.end());
  auto cutoff = std::unique (vec.begin(), vec.end());
  vec.erase(cutoff, vec.end());
}

void biggies(vector<string> &v, const vector<string>::size_type sz)
{
  elimDuplicates(v);
  std::stable_sort(v.begin(), v.end(), [] (const string& s1, const string& s2) {return s1.size() < s2.size();} );
  auto cutoff = std::find_if (v.begin(), v.end(), [sz] (const string s) {return s.size() >=sz;});
  std::for_each(cutoff, v.end(), [] (const string s) {cout <<s<<" ";});
}
  
int main()
{
 vector<string> initial {"the", "quick", "zany", "brown", "fox", "dog", "jumped", "over", "the", "dozing", "blue", "dog"};
 biggies (initial, 4);
  return 0;
}