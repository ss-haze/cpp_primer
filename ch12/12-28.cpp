#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <iostream>
#include <memory>

using std::cin;
using std::cout;
using std::ifstream;
using std::istringstream;
using std::map;
using std::set;
using std::string;
using std::vector;

int main()
{
  ifstream in("data.txt");
  vector<string> lines;
  map<string, set<vector<string>::size_type>> mp;

  vector<string>::size_type line_num = 1;
  for (string line; std::getline(in, line); lines.push_back(line))
  {
    istringstream iss(line);

    for (string word; iss >> word;)
    {
      mp[word].insert(line_num);
    }
    ++line_num;
  }

  while (true)
  {
    cout << "enter word to look for, or q to quit: ";
    string s;
    if (!(cin >> s) || s == "q")
      break;
    const auto &item = mp.find(s);
    if (item != mp.end())
    {
      cout << "The word " << s << " occurs " << item->second.size() << " times" << std::endl;
      for (const auto n : item->second)
        cout << "(Line " << n << ") " << *(lines.begin() + (n - 1)) << std::endl;
    }
    else
      cout << "The word was not found";
    cout << std::endl;
  }
}