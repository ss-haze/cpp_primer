#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <fstream>
#include <algorithm>

int main()

{
  std::ifstream ifs("1029input.txt");

  std::istream_iterator<std::string> in_iter(ifs), eof;

  std::vector<std::string> vec(in_iter, eof);

  std::copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(std::cout, " "));

  return 0;
}