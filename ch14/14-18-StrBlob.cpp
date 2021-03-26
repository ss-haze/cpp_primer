#include "StrBlob.h"
#include <iostream>

main()
{
  StrBlob sb1{"hello", "bye"};
  StrBlob sb2{"hello", "bye"};
  StrBlob sb3{"hello", "bye", "yes"};

  std::cout << (sb1 < sb2) << std::endl;
  std::cout << (sb2 < sb3) << std::endl;

  return 0;
}