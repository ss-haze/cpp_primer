#include <vector>
#include <string>
#include <iostream>

using std::cout;
using std::string;
using std::vector;

int main()
{
  vector<int> vi = {0, 1, 2, 3, 4, 5};
  auto iter = vi.begin();

  while (iter != vi.end())
  {
    if (*iter % 2)
    {
      iter= vi.insert(iter, *iter);
      iter +=2;
    }
    else
      iter=vi.erase(iter);
  }

 
  vector<int> v2;
     cout << v2.capacity();

  return 0;
}