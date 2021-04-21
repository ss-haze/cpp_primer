#include <iostream>
#include <vector>
#include <list>
#include <string>

using std::cout;
using std::list;
using std::string;
using std::vector;

template <typename T, unsigned U>
constexpr unsigned array_size(const T (&arr)[U])
{
  return U;
}

int main()
{
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << array_size(arr) << std::endl;

  string arr2[] = {"yes", "no", "hello"};
  cout << array_size(arr2) << std::endl;

  char arr3[] = "Hello World!";
  cout << array_size(arr3) << std::endl;

  return 0;
}