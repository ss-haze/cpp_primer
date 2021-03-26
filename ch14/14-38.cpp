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

  bool operator()(string &str_length) const
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

  if (!ifs)
  {
    std::cerr << "Error. Could not open file";
    return 1;
  }

  std::vector<string> vs;
  for (string s; ifs >> s; vs.push_back(s))
    ;

  size_t bound_upper, bound_lower;
  std::cout << "Input upper bound: ";
  std::cin >> bound_upper;
  std::cout << "Input lower bound: ";
  std::cin >> bound_lower;

  auto count = std::count_if(vs.begin(), vs.end(), string_limit(bound_upper, bound_lower));
  std::cout << "Total words within specified bounds: " << count;

  return 0;
}