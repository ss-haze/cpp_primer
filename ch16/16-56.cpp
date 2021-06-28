#include <iostream>
#include <string>
#include <sstream>

using namespace::std;

//output non-defined terms
template <typename T>
string debug_rep (const T& t)
{
  ostringstream os;
  os << t;
  return os.str();
}

//output pointers to references, first give address then call above for value
template <typename T>
string debug_rep (T* p)
{
  ostringstream os;
  os << "Pointer p: "<<p;
if (p)
os << " *p: "<<debug_rep (*p);
else 
os <<"P is a null ptr\n";
return os.str();
}


//output strings
string debug_rep (const std::string& s)
{
  return '"'+s+'"';
}

//output ptrs to char as strings
string debug_rep (char * p)
{
  return debug_rep (static_cast<string>(p));
}

//ouput const ptrs to char as strings
string debug_rep(const char *p)
{    
	return debug_rep(static_cast<string>(p));
}

//non-variadic print fn to terminate loop
template<typename T>
ostream& print (ostream& os, const T& t)
{
  return os <<t;
}

//variadic print fn
template<typename T, typename... Args>
ostream& print (ostream& os, const T& t, const Args& ... rest)
{
  os << t <<", ";
  return print (os, rest...);
}

//errorMsg variadic fn. Call debug_rep on each argument in the call to print
template<typename... Args>
ostream& errorMsg (ostream& os, const Args& ... rest)
{
  return print (os, debug_rep(rest)...);
}

int main (){
int x=5; string s {"string variable"};
errorMsg (cerr, 3.1f, 3.14, "string literal", 10, &s);

return 0;
}