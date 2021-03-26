#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

std::string make_plural(size_t ctr, const std::string &word,
                        const std::string &ending = "s")
{
  return (ctr > 1) ? word + ending : word;
}

void elimDuplicates(vector<string> &vec)
{
  std::sort(vec.begin(), vec.end());
  auto cutoff = std::unique(vec.begin(), vec.end());
  vec.erase(cutoff, vec.end());
}

class shorter
{
public:
  bool operator()(const string &s1, const string &s2) const { return s1.size() < s2.size(); }
};

class longer
{
public:
  longer(size_t length) : length_(length) {}

  bool operator()(const string &s) const { return s.size() > length_; }

private:
  size_t length_;
};

class print
{
public:
  void operator()(const string &s) { std::cout << s << " "; }
};

void biggies(vector<string> &words, const vector<string>::size_type sz)
{
  elimDuplicates(words);

  std::stable_sort(words.begin(), words.end(), shorter());

  auto wc = std::find_if(words.begin(), words.end(), longer(sz));

  auto count = words.end() - wc;

  std::cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << std::endl;

  for_each(wc, words.end(), print());
  std::cout << std::endl;
}

int main()
{
  vector<string> initial{"the", "quick", "zany", "brown", "fox", "dog", "jumped", "over", "the", "dozing", "blue", "dog"};
  biggies(initial, 4);
  return 0;
}