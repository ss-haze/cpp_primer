#include <iostream>

using std::cout;

int main (){

  int cnt=10;

  auto f = [&cnt] {return (cnt==0 ? !cnt: !cnt--); };

  for (bool result=false; result!=true; result = f() )
  {
    cout <<result <<" ";
  }

  return 0;
}