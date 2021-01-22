#include <vector>
#include <list>
#include <iostream>

int main()
{
  const char* articles [] {"one", "two", "three"};

  std::cout << articles[1]<<" ";

  for (auto i: articles) std::cout <<i<<" ";

  return 0;
}