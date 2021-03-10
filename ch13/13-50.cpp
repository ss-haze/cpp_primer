#include "String_move.h"
#include <vector>

int main()
{
  const char *c = "Bye!";
  String s0(c);
  String s1("hello");
  String s2(s1);
  String s3 = s2;
  String s4;

  std::vector<String> v;
  v.push_back(s0);
  v.push_back(s1);
  v.push_back(s2);
  v.push_back(s3);
  v.push_back(s4);

  v[4] = std::move(v[1]);
  return 0;
}