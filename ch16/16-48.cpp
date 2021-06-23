#include <iostream>
#include <sstream>
using namespace::std;

template <typename T> 
string debug_rep(const T &t) 
{
    cout <<"const T &t called: ";
    ostringstream ret; // see § 8.3 (p. 321)
    ret << t; // uses T's output operator to print a representation of t
    return ret.str(); // return a copy of the string to which ret is bound 
}

template <typename T> string debug_rep(T *p)
{
    cout <<"T* p called: ";
    ostringstream ret;
    ret << "pointer: " << p; // print the pointer's own value     
    if (p)
    ret << " " << debug_rep(*p);  // print the value to which p points     
    else
    ret << " null pointer"; // or indicate that the p is null     
    return ret.str(); // return a copy of the string to which ret is bound 
}


string debug_rep(const string & s)
{
    cout <<"const string & s called: ";
    return '"' + s +'"';
}

string debug_rep (char* p)
{
    cout <<"char* p called: ";
    return debug_rep(string(p));
}

string debug_rep (const char* p)
{
    cout <<"const char* p called: ";
    return debug_rep(string(p));
}


int main() 
{
    string s ("Hello");
    cout <<&s <<endl;

    cout <<debug_rep(&s)<<endl;

    const string *sp=&s;
    cout <<debug_rep(sp)<<endl;

    cout <<debug_rep("Hi world!")<<endl;

    cout <<debug_rep(s) <<endl;

	return 0;
}