#include <iostream>
#include <string>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void print(int x, const int *b, const int *e)
{
  cout << "i = " << x << endl;
  cout << "j = ";
  for (; b != e; cout << *b++ << " ");
}

void print(int x, const int arr[], size_t size)
{
  cout << "i = " << x << endl;
  cout << "j = ";
  for (decltype(size) i = 0; i != size; ++i)
    cout << arr[i] << " ";
}

void print(int x, const int (*p)[2])
{
  cout << "i = " << x << endl;
  cout << "j = ";
  for (const auto &i : *p)
    cout << i << " ";
}

int main()
{
  int i = 0, j[2] = {0, 1};
  print(i, std::begin(j), std::end(j));
  cout << endl;
  print(i, j, 2);
  cout << endl;
  print(i, &j);

  return 0;
}
