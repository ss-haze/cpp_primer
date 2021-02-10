#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

int main()

{
  std::vector<int> v { std::istream_iterator<int>(std::cin),  std::istream_iterator<int>() };

  std::sort (v.begin(), v.end() );

  std::unique_copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));

  return 0;
}