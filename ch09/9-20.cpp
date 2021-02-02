#include <list>
#include <iostream>
#include <deque>

using std::cout;
using std::deque;
using std::list;

void print(deque<int>::const_iterator b, deque<int>::const_iterator e)
{
  for (; b != e; b++)
    cout << *b << " ";
  cout << std::endl;
}

int main()
{
  list<int> lint{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  deque<int> even, odd;

  for (const auto i : lint)
    (i % 2 == 0 ? even : odd).push_back(i);

  print(even.begin(), even.end());
  print(odd.begin(), odd.end());

  return 0;
}