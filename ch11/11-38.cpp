#include <unordered_map>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using std::cin;
using std::cout;
using std::ifstream;
using std::string;
using std::unordered_map;

void word_count()
{
  unordered_map<string, size_t> word_count;
  string word;
  while (cin >> word)
    ++word_count[word];
  for (const auto &w : word_count)
    cout << w.first << " occurs "
         << w.second << (w.second > 1 ? " times" : " time") << std::endl;
}

unordered_map<string, string> buildMap(ifstream &map_file)
{
  unordered_map<string, string> trans_map;
  string key, value;
  while (map_file >> key && std::getline(map_file, value))
  {
    if (value.size() > 1)
      trans_map[key] = value.substr(1);
    //trans.insert({key, value.substr(1)})
  }
  return trans_map;
}

string transform(unordered_map<string, string> &map_list, string &word)
{
  auto iter = map_list.find(word);
  if (iter == map_list.end())
    return word;
  else
    return iter->second;
}

void word_transform(ifstream &map_file, ifstream &input)
{
  auto trans_map = buildMap(map_file);
  string line, word;
  while (std::getline(input, line))
  {
    std::istringstream iss(line);
    bool first_word = true;
    while (iss >> word)
    {
      if (first_word)
        first_word = false;
      else
        cout << " ";

      cout << transform(trans_map, word);
    }
    std::cout << std::endl;
  }
}

int main()
{
  word_count();

  ifstream ifs_map("map_words.txt"), ifs_input("message.txt");
  if (ifs_map && ifs_input)
    word_transform(ifs_map, ifs_input);
  else
    std::cerr << "There was a problem opening one of the files";

  return 0;
}
