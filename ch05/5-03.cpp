#include <iostream>

using std::cout;

int main () {
  int val=0, sum=0;

  //original 
  while (val<=10)
  {
    sum+=val;
    ++val;
  }
  cout <<sum<<std::endl;

  //rewrite
  val=0; sum=0;
  while (val<=10) sum+=val, ++val;
  cout << sum;

  return 0;

  //The comma operator makes te code less readable.

}