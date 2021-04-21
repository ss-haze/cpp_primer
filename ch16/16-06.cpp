#include <iostream>
#include <vector>
#include <list>
#include <string>

using std::cout;
using std::list;
using std::string;
using std::vector;

template <typename T, unsigned U>
const T *begin_iter(const T (&arr)[U])
{
  return arr;
}

template <typename T, unsigned U>
const T *end_iter(const T (&arr)[U])
{
  return &arr[U - 1];
}

int main()
{
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << *begin_iter(arr) << std::endl;
  cout << *end_iter(arr) << std::endl;

  string arr2[] = {"yes", "no", "hello"};
  cout << *begin_iter(arr2) << std::endl;
  cout << *end_iter(arr2) << std::endl;

  return 0;
}