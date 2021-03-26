#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>

using std::string;
using std::placeholders::_1;

int main()
{
  std::vector<int> vi{0, 1, 2, 3, 4, 5};

  auto iter = std::find_if_not(vi.begin(), vi.end(), (std::bind(std::modulus<int>(), _1, 3)));

  std::cout << (iter != vi.end() ? "The number is divisible" : "The number is not divisible");

  return 0;
}