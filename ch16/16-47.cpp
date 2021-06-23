#include <iostream>

template <typename F, typename T1, typename T2> 
void flip (F fn, T1 &&t1,  T2 &&t2)
{
  fn(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f(int &&v1, int &v2)
{
  std::cout <<v1 << " "<< v2<< std::endl;
}

void g(int v1, int &v2)
{
  std::cout <<v1 << " "<< v2<< std::endl;
}


int main()
{
  int y= 10;
  flip(f, y, 42);  //f has an r-value parameter
  flip(g, y, 42);  //f has an l-value parameter

  return 0;
}