#include <iostream>

using std::cout; 

int main()
{
	cout << "Size of bool: "<<'\t' << '\t' <<sizeof(bool)<<'\n';
	cout << "Size of char: "<< '\t' << '\t' << sizeof(char)<<'\n';
	cout << "Size of wchar_t  " << '\t'  << sizeof(wchar_t) << '\n';
	cout << "Size of char16_t " << '\t' <<  sizeof(char16_t) << '\n';
	cout << "Size of char32_t " << '\t' <<  sizeof(char32_t) << '\n';
	cout << "Size of short: "<< '\t' << '\t' << sizeof(short)<<'\n';
	cout << "Size of int: " << '\t' << '\t' << sizeof(int) << '\n';
	cout << "Size of long: " << '\t' << '\t' << sizeof(long) << '\n';
	cout << "Size of float: " << '\t' << '\t' << sizeof(float) << '\n';
	cout << "Size of double: " << '\t' << sizeof(double) << '\n';
	cout << "Size of long long: " << '\t' << sizeof(long long) << '\n';
	cout << "Size of long double: " << '\t' << sizeof(long double) << '\n';
	
	return 0;
}