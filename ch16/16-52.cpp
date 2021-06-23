#include <iostream>
#include <string>
using std::cout; using std::string; using std::endl;

template <typename T, typename... Args>
void foo(const T& t, const Args&... args)
{
    cout << sizeof...(Args) << endl;// number of type parameters
    cout << sizeof...(args) << endl;
}

int main()
{
    int i = 0; double d = 3.14; string s = "how now brown cow"; 
    foo(i, s, 42, d);    // three parameteres in the pack
    foo(s, 42, "hi");    // two parameters in the pack 
    foo(d, s);           // one parameter in the pack 
    foo("hi");           // no parameters
    foo (1,2,3,4,5);

  return 0;
}