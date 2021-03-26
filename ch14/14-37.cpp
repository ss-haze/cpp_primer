#include <iostream>
#include <algorithm>
#include <vector>

class Equal
{
public:
  Equal(int a)
      : a_(a)
  {
  }
  bool operator()(int b)
  {
    return a_ == b;
  }

private:
  int a_;
};

int main()
{
  std::vector<int> vi{0, 1, 2, 1, 3, 1, 4, 5, 1, 6, 1, 7, 1, 8, 1, 9};

  vi.erase(std::remove_if(vi.begin(), vi.end(), Equal(1)), vi.end());

  for (const auto &i : vi)
    std::cout << i << " ";

  return 0;
}