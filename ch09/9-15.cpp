#include <vector>
#include <iostream>

int main()
{
  std::vector<int> v1{1, 2, 3, 4, 5}, v2{1, 2, 3, 4, 5}, v3{1, 2, 3, 4, 6};

  std::cout << (v1 == v2 ? "v1 and v2 are equal" : "v1 and v2 are not equal") << std::endl;

  std::cout << (v3 == v2 ? "v3 and v2 are equal" : "v3 and v2 are not equal") << std::endl;

  return 0;
}