#include <vector>
#include <iostream>

std::vector<int>::const_iterator find(std::vector<int>::const_iterator b, std::vector<int>::const_iterator e, int x)
{
  for (; b != e; ++b)
    if (*b == x)
      return b;
  return e;
}

inline void found() { std::cout << "Value was found"; }
inline void notFound() { std::cout << "Value was not found"; }

int main()
{
  std::vector<int> v{1, 2, 3, 4, 5};
  auto r = (find(v.begin(), v.end(), 4));
  if (r != v.end())
    found();
  else
    notFound();

  return 0;
}