#include "StrVec.h"

int main()
{
  StrVec v1{"yes", "no", "maybe"};
  StrVec v2{"yes", "no", "maybe"};
  StrVec v3{"yes", "no", "maybe", "perhaps"};

  std::cout << v1 << v2 << v3;

  std::cout << (v1 == v2) << std::endl;

  std::cout << (v2 == v3) << std::endl;

  return 0;
}