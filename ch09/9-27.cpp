#include <forward_list>
#include <iostream>

using std::cout;
using std::forward_list;

int main()
{
  forward_list<int> flst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  auto prev = flst.cbefore_begin();
  for (auto curr = flst.begin(); curr != flst.end();)
  {
    *curr % 2 != 0 ? curr = flst.erase_after(prev) : (++prev, ++curr);
  }

  for (const auto i : flst)
    cout << i << " ";

  return 0;
}