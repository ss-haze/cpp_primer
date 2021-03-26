#include <iostream>

class IfThenElse
{
public:
  char operator()(bool test, char t, char f) const
  {
    return test ? t : f;
  }
};

int main()
{
  int test_item;
  std::cin >> test_item;
  IfThenElse tester;
  std::cout << tester(test_item > 0, 't', 'f');

  return 0;
}