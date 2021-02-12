#include <map>
#include <list>
#include <iostream>
#include <vector>
#include <utility>

using std::list;
using std::map;
using std::pair;
using std::vector;

int main()
{
  map<vector<int>::iterator, int> vi;
  map<list<int>::iterator, int> li;

  vector<int> v{1, 2, 3, 4, 5};
  list<int> l{6, 7, 8, 9, 10};

  vi.insert(pair<vector<int>::iterator, int>(v.begin(), 1));
  //this works. The vector iterator supports the < operator, hence keys for this map can be sorted

  //l.insert(pair<list<int>::iterator, int> (l.begin(), 6));
  //This does not work, since list iterators do not support the < operator, and hence map li cannot be sorted

  return 0;
}