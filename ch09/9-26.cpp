#include <list>
#include <iostream>
#include <vector>

using std::cout;
using std::list;
using std::vector;

int main()
{
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

  vector<int> vec(std::begin(ia), std::end(ia));

  list<int> lst(std::begin(ia), std::end(ia));

  cout << "original list contents: ";
  for (const auto i : lst)
    cout << i << " ";

  cout << "\noriginal vector contents: ";
  for (const auto i : vec)
    cout << i << " ";

  cout << "\nfiltered vector contents: ";
  for (auto iter = vec.begin(); iter != vec.end();)
    iter = (*iter % 2 == 0 ? vec.erase(iter) : ++iter);

  for (const auto i : vec)
    cout << i << " ";

  cout << "\nfiltered list contents: ";
  for (auto iter = lst.begin(); iter != lst.end();)
    iter = (*iter % 2 != 0 ? lst.erase(iter) : ++iter);

  for (const auto i : lst)
    cout << i << " ";

  return 0;
}