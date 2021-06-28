#include <string>
#include <iostream>

using namespace::std;

template <typename T>
ostream& print (ostream& os, const T& t) 
{
    return os << t;
}

template <typename T, typename... Args>
ostream& print (ostream& os, const T & t, const Args&... rest)
{
    os << t <<", "; 
    return print (os, rest...);
}


int main ()
{
    int x = 5; float f = 3.1f; double d = 3.14; string s= "hello", s1="bye";

    print (cout, s)<<endl;
    print (cout, d, x)<<endl;
    print (cout, x,f,d,s,s1);

  return 0;
}