#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <algorithm>

std::string plural(size_t size)
{
  return (size > 1 ? "times" : "time");
}

std::string &remove_case(std::string &s)
{
  for (auto &c : s)
    c = tolower(c);
  return s;
}

std::string &remove_case_and_punctuation(std::string &s)
{
  while (ispunct(s[s.size() - 1]))
    s.erase(s.size() - 1, 1); //remove punct from back
  while (ispunct(s[0]))
    s.erase(0, 1); //remove punct from front

  //s.erase(std::remove_if(s.begin(), s.end(), ispunct), s.end() );
  //Above is much quoted algo for punctuation removal,
  // e.g. see https://stackoverflow.com/questions/19138983/c-remove-punctuation-from-string
  //but this algo removes all letters following a punctuation mark
  // so, for example, ('tis) is totally removed, and (I've) becomes (I)
  // I think it is better to remove punctuation from front and back and keep contractions
  return remove_case(s);
}

int main()
{
  std::ifstream ifs("input.txt");
  std::map<std::string, size_t> words;

  for (std::string input; ifs >> input;)
  {
    remove_case_and_punctuation(input);
    ++words[input];
  }

  for (const auto &s : words)
    std::cout << s.first << " occured " << s.second << " " << plural(s.second) << std::endl;

  return 0;
}