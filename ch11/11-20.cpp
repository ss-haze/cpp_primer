#include <map>
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::map;
using std::string;

int main()
{
  map<string, size_t> word_count;

  for (string word; cin >> word;)
  {
    auto iter = word_count.insert(std::make_pair(word, 1));
    if (!iter.second)
      ++iter.first->second;
    //This method is longer but clearer han the subscript method,
    // where it is difficult to see
    // that a key is created if none is already present.
  }

  for (const auto &w : word_count)
    cout << w.first << " occurs " << w.second << (w.second > 1 ? " times" : " time") << std::endl;

  return 0;
}