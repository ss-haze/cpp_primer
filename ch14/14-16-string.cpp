#include "string.h"

int main()
{
  String s1("Hello");
  String s2("Hello");
  String s3("Hell no");

  std::cout << (s1 == s2) << std::endl;
  std::cout << (s1 == s3) << std::endl;

  return 0;
}