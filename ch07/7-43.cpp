#include <iostream>

class NoDefault
{
  public:
  NoDefault (int ii): i(ii){}
  private:
  int i;
};

class C
{
  public:
  C(): mem(0){}
  private:
  NoDefault mem;
};

int main()
{
  C item;
 
  return 0;
}