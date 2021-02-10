#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::istream_iterator;
using std::ostream_iterator;
using std::string;

int main(int argc, char **argv)
{

  std::ofstream ofs(argv[1]);

  for (int i = 0; i != 100; ++i)
    ofs << i << " ";

  ofs.close();

  if (argc != 4)
  {
    std::cerr << "Incorrect number of arguments. Please input an input file followed by two output files\n";
    return -1;
  }
  std::ifstream ifs(argv[1]);
  std::ofstream ofs1(argv[2]), ofs2(argv[3]);

  istream_iterator<int> input(ifs), eof;
  ostream_iterator<int> odd(ofs1, " "), even(ofs2, "\n");

  std::for_each(input, eof, [&odd, &even](const int x) { x % 2 == 0 ? *even++ = x : *odd++ = x; });

  return 0;
}