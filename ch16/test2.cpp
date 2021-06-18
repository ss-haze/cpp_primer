#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace::std;


//value_type example
template <typename T> 
typename T::value_type top (const T& c)
{
  if (!c.empty()) return c.back();
  else return typename T::value_type();
}

template <typename T, typename F = less<T>>
int compare (const T& lhs, const T& rhs, F f = F())
{
   if (f(lhs, rhs)) return -1;
   if (f(rhs, lhs)) return 1;
   return 0;
}


int main()
{
 vector<int> vs {4,5,6,7,8};
 //cout << top(vs);
 
string s1="a", s2="h";
cout <<compare (s1, s2, greater<decltype(s1)>());

constexpr int s=10;


  return 0;
}