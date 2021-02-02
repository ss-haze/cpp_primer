#include <vector>
#include <iostream>

using std::cout;
using std::vector;

int main()
{
  vector<int> v;
  cout << "Size of v: " << v.size() << " Capacity of v " << v.capacity() << std::endl;

  v.push_back(1);
  cout << "Size of v: " << v.size() << " Capacity of v " << v.capacity() << std::endl;

  for (size_t i = 2; i < 6; i++)
    v.push_back(i);
  cout << "Size of v: " << v.size() << " Capacity of v " << v.capacity() << std::endl;

  v.shrink_to_fit();
  cout << "Size of v: " << v.size() << " Capacity of v " << v.capacity() << std::endl;

  v.push_back(6);
  cout << "Size of v: " << v.size() << " Capacity of v " << v.capacity() << std::endl;

  return 0;
}