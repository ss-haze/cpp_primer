#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using std::map;
using std::string;
using std::vector;

int main ()
{
  vector<string> exclude {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an","a"};
  map <string, size_t> word_count;

  for (string word; std::cin >>word;)
  {
    if (std::find (exclude.begin(), exclude.end(), word) == exclude.end()) ++word_count[word];
  }

  for (const auto & item: word_count) std::cout <<item.first <<" ";
}

/*
What are the advantages of using set?

1) A set is always ordered. 
2) A vector has the order that the user gives it. After multiple insetions, deletions, the vector must be reordered.
3) A vector insert/delete time is linear time. The more items, the longer it takes.
4) A set insert/delete is log(n). 
*/