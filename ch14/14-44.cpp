#include <iostream>
#include <functional>
#include <map>

using std::cout;
using std::endl;
using std::function;
using std::map;
using std::string;

int add(int i, int j) { return i + j; }

auto mod = [](int i, int j) { return i % j; };

struct divide
{
  int operator()(int denominator, int divisor) { return denominator / divisor; }
};

map<string, function<int(int, int)>> binops =
    {
        {"+", add},                                // function ptr
        {"-", std::minus<int>()},                  // library function object
        {"/", divide()},                           // user-defined function object
        {"*", [](int i, int j) { return i * j; }}, // unnamed lambda
        {"%", mod}                                 // named lambda object

};

int main()
{
  bool repeat = true;
  char input;
  while (repeat)
  {
    std::cout << "Please enter your formula (operand space operator operand): ";
    int operand1, operand2;
    std::string operator_type;
    std::cin >> operand1 >> operator_type >> operand2;
    std::cout << binops[operator_type](operand1, operand2) << std::endl;
    std::cout << "Do you wish to repeat (y/n)? ";
    std::cin >> input;
    if (input == 'n')
      repeat = false;
  }
  return 0;
}
