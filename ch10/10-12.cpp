#include "10-12.h"
#include <vector>
#include <fstream>
#include <algorithm>

using std::cout;
using std::fstream;
using std::vector;

bool compareIsbn(const Sales_data &item1, Sales_data &item2)
{
  return item1.isbn() < item2.isbn();
}

int main(int argc, const char **argv)
{
  if (argc < 2)
  {
    std::cerr << "Error: Please input name of program and input data file";
    return -1;
  }

  fstream ifs(argv[1]);

  if (!ifs)
  {
    std::cerr << "Error: could not open input data file";
    return -1;
  }

  vector<Sales_data> vec;

  for (Sales_data input; read(ifs, input); vec.push_back(input))
    ;

  cout << "Before sorting:\n";
  for (const auto &i : vec)
    print(cout, i) << std::endl;

  std::sort(vec.begin(), vec.end(), compareIsbn);

  cout << "After sorting:\n";
  for (const auto &i : vec)
    print(cout, i) << std::endl;

  return 0;
}