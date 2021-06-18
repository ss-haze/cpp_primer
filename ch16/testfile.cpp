#include <iostream>
#include <string>
#include <vector>
#include <type_traits>
using namespace::std;

template <typename It>
auto fcn (It beg, const It& end) -> decltype (*beg)
{
const auto ItStart=beg;
for (;beg != end; ++beg) cout <<*beg<< " ";
cout <<endl;
return *ItStart;
}

template <typename It>
auto fcn2 (It beg,  It end) -> typename remove_reference<decltype(*beg)>::type
{
  return *beg;
}

int main ()
{
  vector<int>v {1,2,3,4,5};
  vector<string> vs {"yes", "no", "what"};
  cout<<fcn(v.begin(), v.end())<<endl;
  cout<<fcn(vs.begin(), vs.end())<<endl;

  cout << fcn2 (vs.begin(), vs.end());
  return 0;
}