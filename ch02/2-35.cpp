#include <iostream>

int main()
{
  const int i = 42;       //is a const int
  auto j=i;               //j is an int
  const auto &k=i;        //k is a const int &
  auto *p=&i;             //p is a const int *
  const auto j2 = i, &k2=i;      //j2 is a const int, k2 is a const int &

  return 0;
}