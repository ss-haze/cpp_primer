#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using std::cout;
using std::ifstream;
using std::string;

class string_limit
{
public:
  string_limit(size_t upper, size_t lower)
      : bound_upper_(upper),
        bound_lower_(lower) {}

  bool operator()(const string &str_length) const
  {
    return str_length.size() <= bound_upper_ &&
           str_length.size() >= bound_lower_;
  }

private:
  size_t bound_lower_;
  size_t bound_upper_;
};

int main()
{
  ifstream ifs("input.txt");

  if (!ifs.is_open())
  {
    std::cerr << "Error. Could not open file";
    return 1;
  }

  size_t bound_upper, bound_lower;
  std::cout << "Input upper bound: ";
  std::cin >> bound_upper;
  std::cout << "Input lower bound: ";
  std::cin >> bound_lower;
  string_limit sl(bound_upper, bound_lower);

  size_t above_bounds = 0, within_bounds = 0;
  for (string s; ifs >> s;)
    if (sl(s))
      ++within_bounds;
    else
      ++above_bounds;

  std::cout << "Total words within specified bounds: " << within_bounds << "\nTotal words above specified bounds: " << above_bounds;

  return 0;
}