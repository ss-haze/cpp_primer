#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

bool strings_subset_test(vector<int> const &lhs, vector<int> const &rhs)
{
  if (lhs.size() > rhs.size())
    return strings_subset_test(rhs, lhs);

  for (unsigned i = 0; i != lhs.size(); ++i)
  {
    if (lhs[i] != rhs[i])
      return false;
  }
  return true;
}

int main()
{
  vector<int> left{1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> right{1, 2, 3, 4, 5, 6};

  cout << (strings_subset_test(left, right) ? "Strings are a subset" : "strings are not a subset");

  return 0;
}