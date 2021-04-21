#include <iostream>
using std::cout;

template <typename T, unsigned U>
void print(const T (&arr)[U])
{
  for (const auto i : arr)
    cout << i << " ";
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  print(arr);

  print("Hello World!");
  return 0;
}