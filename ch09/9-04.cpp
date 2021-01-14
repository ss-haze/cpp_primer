#include <vector>
#include <iostream>

bool find(std::vector<int>::const_iterator b, std::vector<int>::const_iterator e, int x)
{
  for (; b != e; ++b)
    if (*b == x)
      return true;
  return false;
}

inline void found() { std::cout << "Value was found"; }
inline void notFound() { std::cout << "Value was not found"; }

int main()
{
  std::vector<int> v{1, 2, 3, 4, 5};
  if (find(v.begin(), v.end(), 40))
    found();
  else
    notFound();

  return 0;
}