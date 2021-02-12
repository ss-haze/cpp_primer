#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using std::map;
using std::string;
using std::vector;

void create_family(map<string, vector<string>> &m)
{
  string input;
  std::cout << "Please add family name: ";
  std::cin >> input;
  auto iter = m.insert(std::pair<string, vector<string>>(input, {}));
  if (!iter.second)
    std::cerr << "Error: That family name has already been created\n";
}

void add_child(map<string, vector<string>> &m)
{
  std::cout << "To which family do you wish to add?";
  string input;
  std::cin >> input;
  auto iter = m.find(input);
  if (iter != m.end())
  {
    string child;
    std::cout << "Please enter the name of the child you wish to add: ";
    std::cin >> child;
    iter->second.push_back(child);
  }
  else
    std::cerr << "Error: That family name has not yet been created\n";
}

void print(map<string, vector<string>> &m)
{
  if (m.empty())
  {
    std::cerr << "Error: The map is currently empty\n";
    return;
  }

  for (const auto &pr : m)
  {
    std::cout << pr.first << ": ";
    for (const auto &vs : pr.second)
    {
      std::cout << vs << " ";
    }
    std::cout << std::endl;
  }
}

int main()
{
  vector<string> children;
  map<string, vector<string>> family;

  int menu = 0;
  do
  {
    std::cout << "Please choose from one of the following: \n 1) Add a new family \n 2) Add a child to a family \n 3) Print Map\n 4) Exit\n";
    std::cin >> menu;
    switch (menu)
    {
    case 1:
      create_family(family);
      break;

    case 2:
      if (family.empty())
        std::cerr << "Error: Map currently has no families\n";
      else
        add_child(family);
      break;

    case 3:
      print(family);
      break;

    case 4:
      break;

    default:
      std::cerr << "Error: Please input a valid choice\n";
      break;
    }
  } while (menu != 4);

  return 0;
}