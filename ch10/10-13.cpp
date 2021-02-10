#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

bool stringSize(const string &s)
{
  return (s.size() >= 5);
}

int main(int argc, char **argv)
{

  vector<string> v{"yes", "no", "whatever", "perhaps", "nyet", "oui", "achtung"};

  const auto cutoff = std::stable_partition(v.begin(), v.end(), stringSize);

  for (auto b = v.cbegin(); b != cutoff; ++b)
    std::cout << *b << " ";

  return 0;
}