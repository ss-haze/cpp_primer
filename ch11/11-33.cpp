#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using std::cout;
using std::ifstream;
using std::istringstream;
using std::map;
using std::string;

map<string, string> buildMap(ifstream &map_file)
{
  map<string, string> trans_map;
  string key, value;
  while (map_file >> key && std::getline(map_file, value))
  {
    if (value.size() > 1)
      trans_map[key] = value.substr(1);
      //trans.insert({key, value.substr(1)})
  }
  return trans_map;
}

string transform(std::map<string, string> &map_list, string &word)
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
    istringstream iss(line);
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

  ifstream ifs_map("map_words.txt"), ifs_input("message.txt");
  if (ifs_map && ifs_input)
    word_transform(ifs_map, ifs_input);
  else
    std::cerr << "There was a problem opening one of the files";
}