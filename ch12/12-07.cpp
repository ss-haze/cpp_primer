#include <vector>
#include <iostream>
#include <memory>

using std::cin;
using std::cout;
using std::vector;

std::shared_ptr<vector<int>> factory()
{
  return std::make_shared<vector<int>>();
}

std::shared_ptr<vector<int>> input(std::shared_ptr<vector<int>> vec)
{
  for (int in; cin >> in; vec->push_back(in))
    ;
  return vec;
}

void print(std::shared_ptr<vector<int>> vec)
{

  for (const auto n : *vec)
    cout << n << " ";
}

int main()
{
  auto vec = input(factory());
  print(vec);

  return 0;
}