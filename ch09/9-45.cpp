#include <string>
#include <iostream>
#include <vector>

using std::cout;
using std::string;
using std::vector;

string replace_string(const vector<string> &v)
{
  string final;
  return final.insert(0, *(v.begin() + 1)).append(" " + *(v.begin()) + " " + *(v.end() - 1));
}

int main()
{
  const vector<vector<string>> v1{{"James", "Mr", "Snr"}, {"Ahmed", "Mrs", ""}, {"Olsen", "Ms", "Jr"}};
  vector<string> final;

  for (auto &i : v1)
    final.push_back(replace_string(i));

  for (const auto &i : final)
    cout << i << std::endl;

  return 0;
}