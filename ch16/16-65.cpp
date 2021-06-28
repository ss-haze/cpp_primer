#include <iostream>
#include <sstream>
#include <string>

using namespace::std;

//general reference template
template <typename T>
string debug_rep(const T &t)
{
	ostringstream ret;
	ret << t;
	return ret.str();
}

//general pointer template
template <typename T>
string debug_rep(T *p)
{
	ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p); 
		ret << "null pointer";
	return ret.str();
}

//nontemplate function
string debug_rep(const string &s)
{
	return '"' + s + '"';
}

// specialized instantiation of pointer template using char * for T
template <>
string debug_rep(char *p)
{
	cout << "specialized template char * invoked\n";
	return debug_rep(string(p));
}

//specialized instantiation of pointer template using const char * for T
template <>
string debug_rep(const char *p)
{

	cout << "specialized template const char * invoked\n";
	return debug_rep(string(p));
}

int main() {
	string s("hello");
	cout << debug_rep(s) << endl;
	cout << debug_rep(&s) << endl;
	cout << debug_rep("hi") << endl;
	char a[] = "test";
  char *ptr = a; 
	std::cout << debug_rep(ptr) << endl;
	return 0;
}