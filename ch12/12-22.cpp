#include "ConstStrBlob.h"
#include "ConstStrBlobPtr.h"
#include <fstream>
#include <iostream>
#include <sstream>

int main()
{

  const ConstStrBlob s{"hello", "there", "how", "are", "you"};

  auto iter = s.begin();

  for (decltype(s.size()) b = 0; b != s.size(); ++b)
  {
    std::cout << iter.deref() << " ";
    iter.incr();
  }

  return 0;
}
