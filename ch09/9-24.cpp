#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main()
{
  vector<int> v;

  std::cout << v.at(0);
  // terminate called after throwing an instance of 'std::out_of_range'

  std::cout << v[0]; //program terminated

  std::cout << *(v.begin()); //program terminated

  std::cout << v.front(); //program terminated

  return 0;
}