#include <string>
#include <iostream>

using namespace::std;

template <typename T, typename... Args>
void foo (const T& i, const Args& ... args)
{
 cout << "Size of Args: "<<sizeof... (Args) <<endl
        <<"Size of args: "<<sizeof... (args) <<endl; 

}

int main ()
{
  int i =0; double d= 3.14; string s= "how now brown cow";

  foo(i, s, 42, d);
  foo (s, 42, "hi");
  foo (d,s);
  foo ("hi");

  return 0;
}