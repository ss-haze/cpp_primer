#include "HasPtr.h"

int main()
{

  HasPtr a ("hello", 5);
   HasPtr b ("yes", 50);

   b=a;

// when separate move and copy assignment operators are not used, 
// the copy and swap method is used for both moved and copied HasPtr objects
// this method calls the swap function, which takes longer than the separate move and assignment methods

  return 0;
}