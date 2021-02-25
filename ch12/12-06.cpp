#include <vector>
#include <iostream>

using std::cin;
using std::cout;
using std::vector;

vector<int> *factory()
{
  return new vector<int>;
}

vector<int> *input(vector<int> *vec)
{
  for (int in; cin >> in; vec->push_back(in))
    ;
  return vec;
}

void print(vector<int> *vec)
{
  for (const auto n : *vec)
    cout << n << " ";
}

int main()
{
  auto vec = input(factory());
  print(vec);
  delete vec;

  return 0;
}
