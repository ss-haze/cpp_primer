#include <memory>
#include <string>
#include <iostream>

int main()
{
  std::allocator<std::string> alloc;
  auto const p = alloc.allocate(5);

  auto q = p;
  std::string input;
  while (q != p + 5 && std::cin >> input)
    alloc.construct(q++, input);

  while (q != p)
  {
    std::cout << *(--q);
    alloc.destroy(q);
  }

  alloc.deallocate(p, 5);

  return 0;
}