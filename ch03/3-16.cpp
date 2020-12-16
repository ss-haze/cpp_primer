#include <iostream>
#include <vector>
#include <string>

using std::vector; using std::cout;  
using std::cin; using std::endl; using std::string;

void print_int(const vector<int> &vi)
{
  for (const auto & i: vi) cout <<i <<" ";
  cout <<'\n';
}

void print_string(const vector<string> &vs)
{
  for (const auto & i: vs) cout <<i <<" ";
  cout <<'\n';
}

int main()
{
  vector<int> v1;               
  vector<int> v2(10);           
  vector<int> v3(10, 42);       
  vector<int> v4{10};           
  vector<int> v5{10, 42};       
  vector<string> v6{10};       
  vector<string> v7{10, "hi"};  

  print_int(v1);
  print_int(v2);
  print_int(v3);
  print_int(v4);
  print_int(v5);
  print_string(v6);
  print_string(v7);

  return 0;
}