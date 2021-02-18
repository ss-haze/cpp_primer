#include <iostream>
#include <map>
#include <string>
#include <set>

using std::cout;
using std::string;

int main()
{
  std::multimap<string, string> authors;
  authors.insert({"Hardy, Thomas", "Tess Of The D'Urbervilles"});
  authors.insert({"Hardy, Thomas", "Far From The Madding Crowd"});
  authors.insert({"Hardy, Thomas", "Jude The Obscure"});

  string search_item("Hardy, Thomas"), erase_item("Jude The Obscure");

  for (const auto &i : authors)
    cout << i.first << ": " << i.second << std::endl;

  //sort values alphabetically
  std::map<string, std::set<string>> authors_in_order;

  for (const auto &item : authors)
  {
    authors_in_order[item.first].insert(item.second);
  }

  for (const auto &item : authors_in_order)
  {
    cout << item.first << ": ";
    for (const auto &title : item.second)
      cout << title << " ";
  }

  return 0;
}