#include <string>
#include <cstring>
#include <memory>
#include <iostream>

int main()
{

  int size;
  std::cout << "Input size of string: ";
  std::cin >> size;

  std::cin.ignore();

  char *c = new char[size + 1];

  std::cin.get(c, size + 1);

  std::cout << c;

  delete[] c;

  return 0;
}