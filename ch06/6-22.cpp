#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void swap_ptrs_method1(int *&p1, int *&p2) //uses reference to pointer
{
  auto temp = p1;
  p1 = p2;
  p2 = temp;
}

void swap_ptrs_method2(int **p1, int **p2) //uses pointer to pointer
{
  int *temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

int main()
{
  int a = 10, b = 5;

  int *lhs = &a, *rhs = &b;

  cout << "&lhs = " << lhs << " and *lhs = " << *lhs << endl;
  cout << "&rhs = " << rhs << " and *rhs = " << *rhs << endl
       << endl;

  swap_ptrs_method1(lhs, rhs);

  cout << "&lhs = " << lhs << " and *lhs = " << *lhs << endl;
  cout << "&rhs = " << rhs << " and *rhs = " << *rhs << endl
       << endl;

  swap_ptrs_method2(&lhs, &rhs);

  cout << "&lhs = " << lhs << " and *lhs = " << *lhs << endl;
  cout << "&rhs = " << rhs << " and *rhs = " << *rhs << endl;

  return 0;
}