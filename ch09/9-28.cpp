#include <forward_list>
#include <string>
#include <iostream>

using std::cout;
using std::forward_list;
using std::string;

void insert(forward_list<string> &fl, const string &test, const string &insert)
{
  auto prev = fl.before_begin();
  bool found = false;

  for (auto curr = fl.begin(); curr != fl.end(); prev = curr++)
  {
    if (*curr == test)
    {
      fl.insert_after(curr, insert);
      found = true;
    }
  }
  if (!found)
    fl.insert_after(prev, insert);
}

int main()
{
  forward_list<string> flst{"one", "two", "three", "two", "four"};
  insert(flst, "two", "insert_in");
  for (const auto &i : flst)
    cout << i << " ";
  cout << std::endl;

  insert(flst, "default", "insert_end");
  for (const auto &i : flst)
    cout << i << " ";

  return 0;
}