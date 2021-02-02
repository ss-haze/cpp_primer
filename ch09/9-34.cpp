#include <vector>
#include <iostream>

using std::cout;
using std::vector;

int main()
{
  vector<int> vi{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
 auto iter = vi.begin();
    /* 
    while (iter != vi.end())
    if (*iter % 2)
      iter = vi.insert(iter, *iter);
      ++iter;
  } */

  // The above code will infintely loop as soon as it hits an odd number.

  //soln:
 
  while (iter != vi.end())
  { // The loop body should be a block.
    if (*iter % 2)
    {
      iter = vi.insert(iter, *iter);
      iter += 2;
    }
    else
      ++iter;
  }

  for (const auto i : vi)
    cout << i << " ";
  return 0;
}