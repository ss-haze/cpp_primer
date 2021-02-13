#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using std::multimap;
using std::pair;
using std::string;
using std::vector;

void create_family(multimap<string, string> &m)
{

  string input, child;
  std::cout << "Please add family name: ";
  std::cin >> input;
  std::cout << "Please add child name: ";
  std::cin >> child;
  auto iter = m.insert({input, child});
}

void print(multimap<string, string> &m)
{
  if (m.empty())
  {
    std::cerr << "Error: The map is currently empty\n";
    return;
  }

  for (const auto &pr : m)
  {
    std::cout << pr.first << ": " << pr.second;
    std::cout << std::endl;
  }
}

int main()
{
  multimap<string, string> family;

  int menu = 0;
  do
  {
    std::cout << "Please choose from one of the following: \n 1) Add a new family \n 2) Print Map\n 3) Exit\n";
    std::cin >> menu;
    switch (menu)
    {
    case 1:
      create_family(family);
      break;

    case 2:
      print(family);
      break;

    case 3:
      break;

    default:
      std::cerr << "Error: Please input a valid choice\n";
      break;
    }
  } while (menu != 3);

  return 0;
}