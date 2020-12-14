#include <iostream>

int main ()
{
int x, sum=0;
std::cout <<"Please input some numbers: ";
for (; std::cin >>x; sum+=x);
std::cout <<"The sum of the numbers is "<<sum;

return 0;
}