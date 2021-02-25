#include <iostream>
#include <string>
#include <memory>

using std::string;
using std::unique_ptr;

int main()
{
  unique_ptr<string> p(new string("hello"));
  //unique_ptr<string> p1(p); // copy
  //                      ^
  // Error: Function cannot be referenced - it is a deleted function
  //
  //unique_ptr<string> p3 = p1; // assign
  //                      ^
  // Error: Function cannot be referenced - it is a deleted function
}