#include <iostream>

void f(int v1, int &v2)
{
  std::cout <<v1 << " "<< ++v2<< std::endl;
}

template <typename F, typename T1, typename T2> 
void flip1 (F f, T1 t1, T2 t2)
{
  f(t2, t1);
}


int main()
{
int x=5, y= 10;
flip1( f, x, y);

return 0;
}