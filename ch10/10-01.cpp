#include <iostream>
#include <algorithm>
#include <vector>

int main()
{

  std::vector<int> v;
  std::vector<int> done;

  for (int input; std::cin >> input; v.push_back(input))
    ;

  for (const auto i : v)
  {
    if (std::find(done.cbegin(), done.cend(), i) == done.cend())
    {
      std::cout << "The value " << i << " occurs " << std::count(v.cbegin(), v.cend(), i) << " times\n";
      done.push_back(i);
    }
  }

  return 0;
}