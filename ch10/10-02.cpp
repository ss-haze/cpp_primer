#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::string;

int main()
{

  std::vector<string> v;
  std::vector<string> done;

  for (std::string input; std::cin >> input; v.push_back(input))
    ;

  for (const auto i : v)
  {
    if (std::find(done.cbegin(), done.cend(), i) == done.cend())
    {
      std::cout << "The word " << i << " occurs " << std::count(v.cbegin(), v.cend(), i) << " times\n";
      done.push_back(i);
    }
  }

  return 0;
}