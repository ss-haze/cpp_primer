#include <iostream>

int main ()
{
  int a=3, b=4;
  decltype(a) c = a;        //c is an int
  decltype ((b)) d = a;     //b is an int &

  //a=3, b=4, c=3, d=3

  ++c;    //a=3, b=4, c=4, d=3                     
  ++d;    //a=4, b=4, c=4, d=4                    
}