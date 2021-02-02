#include <list>
#include <forward_list>
#include <iostream>

using std::cout;
using std::forward_list;
using std::list;

void insert(forward_list<int> &flist)
{
  auto prev = flist.before_begin();

  for (auto curr = flist.begin(); curr != flist.end();)
  {
    if (*curr % 2)
    {
      prev = flist.insert_after(curr, *curr);
      ++curr;
      ++curr;
    }
    else
      curr = flist.erase_after(prev);
  }
}

void insert(list<int> &lst)
{
  for (auto iter=lst.begin(); iter!=lst.end();)
  if (*iter % 2)
  {
    iter=lst.insert(iter, *iter);
    ++iter; ++iter;
  }
  else iter=lst.erase(iter);
}

int main()
{
  forward_list<int> fl = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  list<int> l = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  insert(fl);
  insert(l);

  for (const auto i : fl)
    cout << i << " ";
  cout << std::endl;

  for (const auto i : l)
    cout << i << " ";
  cout << std::endl;

  return 0;
}