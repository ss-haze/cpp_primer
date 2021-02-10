#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using std::cout;
using std::list;
using std::string;
using std::vector;

int main()
{
  vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5};
  list<int> li;

  std::sort(vi.begin(), vi.end());
  std::unique_copy(vi.begin(), vi.end(), std::back_inserter(li) );

  for (const auto i : li)
    cout << i << " ";
}