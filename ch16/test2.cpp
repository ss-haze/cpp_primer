
#include <iostream>
int main()
{
  char const *ptr = "hello";
  const char arr[] = "hello";
  std::cout
      << "the size of ptr is " << sizeof(ptr) << '\n'
      << "the size of arr is " << sizeof(arr);

  return 0;
}