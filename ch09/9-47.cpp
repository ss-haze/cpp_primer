#include <string>
#include <iostream>

using std::cout;
using std::string;

int main()
{

  string s = "ab2c3d7R4E6";
  string number = "0123456789";
  string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

  //find numbers in s using find_first_of
  for (string::size_type pos = 0; (pos = s.find_first_of(number, pos)) != string::npos; ++pos)
    cout << "The number " << s[pos] << " was found at position " << pos << std::endl;

  //find chars in s using find_first_of
  for (string::size_type pos = 0; (pos = s.find_first_of(alphabet, pos)) != string::npos; ++pos)
    cout << "The character " << s[pos] << " was found at position " << pos << std::endl;


 //find numbers in s using find_first_not_of
  for (string::size_type pos = 0; (pos = s.find_first_not_of(alphabet, pos)) != string::npos; ++pos)
    cout << "The number " << s[pos] << " was found at position " << pos << std::endl;


  //find chars in s using find_first_not_of
  for (string::size_type pos = 0; (pos = s.find_first_not_of(number, pos)) != string::npos; ++pos)
    cout << "The character " << s[pos] << " was found at position " << pos << std::endl;

  return 0;
}