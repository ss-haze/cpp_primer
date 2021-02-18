#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::multimap;
using std::string;

int main()
{
  multimap<string, string> authors;
  authors.insert({"Hardy, Thomas", "Tess Of The D'Urbervilles"});
  authors.insert({"Hardy, Thomas", "Far From The Madding Crowd"});
  authors.insert({"Hardy, Thomas", "Jude The Obscure"});

  string search_item("Hardy, Thomas"), erase_item("Jude The Obscure");

    for (const auto &i : authors)
    cout << i.first << ": " << i.second << std::endl;

  for (auto iter = authors.equal_range(search_item); iter.first != iter.second; ++iter.first)
  {
    if (iter.first->second == erase_item)
    {
      authors.erase(iter.first);
      break;
    }
  }

  for (const auto &i : authors)
    cout << i.first << ": " << i.second << std::endl;

  return 0;
}