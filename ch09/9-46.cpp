#include <string>
#include <iostream>
#include <vector>

using std::cout;
using std::string;
using std::vector;

string &replace_string(string &name, const string &prefix, const string &suffix)
{
  return name.insert(0, prefix + ". ").insert(name.size(), ", " + suffix);
}

int main()
{
  string name = "James", prefix = "Mr", suffix = "Snr";
  cout << replace_string(name, prefix, suffix);

  return 0;
}