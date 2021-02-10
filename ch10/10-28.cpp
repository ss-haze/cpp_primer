#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <deque>

using std::cout;
using std::list;
using std::string;
using std::vector;
using std::deque;

template <typename T>
void print (T & container)
{
  for (const auto & i: container) cout <<i << " ";
}

int main()
{
  vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
  deque<int> front;
  vector<int> back;
  list<int> middle;

std::copy (vi.begin(), vi.end(), std::front_inserter (front));  //reversed order
std::copy (vi.begin(), vi.end(), std::back_inserter (back));    //same order
std::copy (vi.begin(), vi.end(), std::inserter (middle, middle.begin())); //same order

print(front); cout <<std::endl;
print(back); cout <<std::endl;
print(middle); cout <<std::endl;

return 0;
}